#include <err.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include <sysexits.h>

#include "../libcross/nitems.h"
#include "../libcross/strtonum.h"
#include "../libarray/array.h"

#include "geom.h"
#include "maze.h"

void
carve_maze(struct maze *m);

void
carve_maze_part(struct maze *m, struct pt from);

bool
can_carve(const struct maze *m, struct pt po, enum dir d);

int
main(int argc, char **argv) {
	size_t w, h;

	if (argc == 2) {
		const char *e;
		long long x = strtonum(argv[1], 1, 400, &e);
		if (e) {
			errno = EDOM;
			err(EX_USAGE, "size must 1-400");
		}
		w = x;
		h = x;
	} else if (argc == 3) {
		const char *e;
		long long x = strtonum(argv[1], 1, 400, &e);
		if (e) {
			errno = EDOM;
			err(EX_USAGE, "width must 1-400");
		}
		e = NULL;
		long long y = strtonum(argv[2], 1, 400, &e);
		if (e) {
			errno = EDOM;
			err(EX_USAGE, "height must 1-400");
		}
		w = x;
		h = y;
	} else {
		errx(EX_USAGE, "usage: %s size | %s width height", argv[0], argv[0]);
	}

	struct maze *m = maze_create(w, h);

	carve_maze(m);

	for (int y = 0; y < m->height; y++) {
		for (int x = 0; x < m->width; x++) {
			putchar(cell_str(maze_cell_at(m, (struct pt){x, y})));
		}
		puts("");
	}

	maze_free(m);
	return 0;
}

void
carve_maze(struct maze *m) {
	/* Q: Why do we carve in a loop?
	   A: The carving algorithm can trap itself, i.e. it is not guaranteed
	   to fill the available space. We can brute force around this by
	   carving a maze from every point (x, y) where x and y are both odd.
	   This ensures that the maze is filled as much as possible and that
	   only odd points are carved. */
	for (int y = 1; y < m->height - 1; y += 2) {
		for (int x = 1; x < m->width - 1; x += 2) {
			carve_maze_part(m, (struct pt){x, y});
		}
	}
}

void
carve_maze_part(struct maze *m, struct pt from) {
	struct array *frontier = array_create(10);
	array_insert(frontier, &from);

	while (!array_empty(frontier)) {
		struct pt *curr = (struct pt *)array_pick(frontier);
		struct array *unmade = array_create(4);

		for (int i = 0; i < nitems(DIRS); i++) {
			enum dir *d = (enum dir *)&DIRS[i];
			if (can_carve(m, *curr, *d)) {
				array_insert(unmade, d);
			}
		}

		if (!array_empty(unmade)) {
			enum dir d = *(enum dir *)array_pick(unmade);

			struct pt *wall = pt_add_dir_p(*curr, d);
			struct pt *beyond = pt_add_dir_p(*wall, d);

			maze_set_cell(m, *wall, CLEAR);
			maze_set_cell(m, *beyond, CLEAR);

			array_insert(frontier, beyond);
		} else {
			array_remove_elems(frontier, curr, (elem_eq)pt_eq_p);
		}
	}
}

bool
can_carve(const struct maze *m, struct pt po, enum dir d) {
	struct pt p = pt_add_dir(pt_add_dir(po, d), d);

	if (p.x < 0 || p. y < 0 || p.x >= m->width || p.y >= m->height)
		return false;

	if (maze_cell_at(m, p) != WALL)
		return false;

	p = pt_add_dir(p, d);

	if (p.x >= m->width) return false;
	if (p.y >= m->height) return false;

	return true;
}

