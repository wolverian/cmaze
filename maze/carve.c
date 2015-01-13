#include <stdlib.h>
#include <stdbool.h>

#include "../libcross/nitems.h"
#include "../libarray/array.h"

#include "geom.h"
#include "maze.h"
#include "carve.h"

void
carve_maze_part(struct maze *m, struct pt from);

bool
can_carve(const struct maze *m, struct pt po, enum dir d);

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
