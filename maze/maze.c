#include <err.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include <sysexits.h>

#include "../libarray/array.h"

typedef int cell;

enum celltype { WALL, CLEAR };

struct maze {
	int64_t width, height;
	cell *a;
};

struct pt {
	int x, y;
};

enum dir {UP, RIGHT, DOWN, LEFT};

const enum dir DIRS[] = {UP, RIGHT, DOWN, LEFT};

struct maze *
maze_create(size_t width, size_t height) {
	if (height > 0 && height > INT64_MAX / width) {
		errno = ENOMEM;
		err(EX_SOFTWARE, "overflow");
	}

	struct maze *m = malloc(sizeof(struct maze));

	m->width = width;
	m->height = height;
	m->a = reallocarray(NULL, width*height, sizeof(cell));
	
	return m;
}

void
maze_free(struct maze *m) {
	free(m->a);
	free(m);
}

cell
maze_cell_at(const struct maze *m, struct pt p) {
	if (p.x >= m->width) {
		errno = EDOM;
		err(EX_SOFTWARE, "x out of bounds: %d", p.x);
	}
	if (p.y >= m->height) {
		errno = EDOM;
		err(EX_SOFTWARE, "y out of bounds: %d", p.y);
	}

	return m->a[p.y*m->width + p.x];
}

void
maze_set_cell(const struct maze *m, struct pt at, cell c) {
	if (at.x >= m->width) {
		errno = EDOM;
		err(EX_SOFTWARE, "x out of bounds: %d", at.x);
	}
	if (at.y >= m->height) {
		errno = EDOM;
		err(EX_SOFTWARE, "y out of bounds: %d", at.y);
	}
	
	m->a[at.y*m->width + at.x] = c;
}

char
cell_str(cell c) {
	switch (c) {
		case 0: return '#';
		case 1: return ' ';
	}
	errx(EX_SOFTWARE, "invalid cell");
	// not reached
	return 0;
}

bool
pt_eq(struct pt a, struct pt b) {
	return a.x == b.x && a.y == b.y;
}

bool
pt_eq_p(struct pt *a, struct pt *b) {
	return a->x == b->x && a->y == b->y;
}

struct pt
pt_add_dir(struct pt p, enum dir d) {
	int x = p.x;
	int y = p.y;
	switch (d) {
		case UP: y -= 1; break;
		case RIGHT: x += 1; break;
		case DOWN: y += 1; break;
		case LEFT: x -= 1; break;
	}
	return (struct pt){x, y};
}

struct pt *
pt_add_dir_p(struct pt p, enum dir d) {
	struct pt *to = malloc(sizeof(struct pt));
	struct pt temp = pt_add_dir(p, d);
	to->x = temp.x;
	to->y = temp.y;
	return to;
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
