#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libcross/nitems.h"
#include "../libarray/array.h"

#include "geom.h"
#include "maze.h"
#include "carve.h"

#define min(a,b) \
	({	__typeof__ (a) _a = (a); \
		__typeof__ (b) _b = (b); \
		_a < _b ? _a : _b; })

struct room_params {
	struct pt min, max;
};

static void
carve_maze_rooms(struct maze *, size_t, struct room_params);

static void
carve_maze_part(struct maze *, struct pt, region reg);

static bool
can_carve(const struct maze *, struct pt, enum dir);

static void
carve_connections(struct maze *m, size_t n);

void
carve_maze(struct maze *m) {
	carve_maze_rooms(m, 20, (struct room_params){
		.min = (struct pt){.x = 3, .y = 3},
		.max = (struct pt){.x = 9, .y = 9}
	});

	/* Q: Why do we carve in a loop?
	   A: The carving algorithm can trap itself, i.e. it is not guaranteed
	   to fill the available space. We can brute force around this by
	   carving a maze from every point (x, y) where x and y are both odd.
	   This ensures that the maze is filled as much as possible and that
	   only odd points are carved. */
	   
	for (int y = 1; y < m->height - 1; y += 2) {
		for (int x = 1; x < m->width - 1; x += 2) {
			struct pt here = (struct pt){x, y};
			
			if (maze_cell_at(m, here) != CLEAR) {
				/*	We can safely say this is a new region because:
				 	1. This cell is not CLEAR.
				 	2. We jump two coordinates at a time (i.e. (1,1)->(3,3)), so we have not started a carve from any of this cell's neighbours.
				 	3. We carve two cells at a time in any direction in carve_maze_part.
				 	From these we see we know that this cell's neighbours are not carved.
				 	
				 	Just to make sure, we assert this property below.
				 */

				assert(maze_cell_at(m, pt_add_dir(here, UP)) != CLEAR);
				assert(maze_cell_at(m, pt_add_dir(here, RIGHT)) != CLEAR);
				assert(maze_cell_at(m, pt_add_dir(here, DOWN)) != CLEAR);
				assert(maze_cell_at(m, pt_add_dir(here, LEFT)) != CLEAR);
							
				carve_maze_part(m, here, maze_new_region(m));
			}
		}
	}
	
	carve_connections(m, 15);
}

struct room {
	struct pt min, max;
};

struct room *
room_create(struct pt min, struct pt size) {
	struct room *r = malloc(sizeof(struct room));
	r->min.x = min.x;
	r->min.y = min.y;
	r->max.x = min.x + size.x;
	r->max.y = min.y + size.y;
	return r;
}

static void
room_free(struct room *r) {
	free(r);
}

static bool
rooms_overlap(struct room *a, struct room *b) {
	return (a->min.x < b->max.x && a->max.x > b->min.x &&
		a->min.y < b->max.y && a->max.y > b->min.y);
}

static void
carve_maze_rooms(struct maze *m, size_t max_tries, struct room_params rp) {
	struct array *rooms = array_create(10);

	for (size_t i = 0; i < max_tries; i++) {
		/* Is this mess even correct? */
		size_t y = arc4random_uniform(m->height/2)*2 + 1;
		size_t x = arc4random_uniform(m->width/2)*2 + 1;
		size_t height = arc4random_uniform(rp.max.y/2)*2 + rp.min.y;
		size_t width = arc4random_uniform(rp.max.x/2)*2 + rp.min.x;

		struct room *r = room_create((struct pt){x, y}, (struct pt){width, height});

		bool overlap = false;

		for (size_t j = 0; j < array_size(rooms); j++) {
			if (rooms_overlap(r, array_get(rooms, j))) {
				overlap = true;
			}
		}

		bool in_bounds = r->max.x < m->width && r->max.y < m->height;

		if (overlap || !in_bounds)
			room_free(r);
		else
			array_insert(rooms, r);
	}

	for (size_t i = 0; i < array_size(rooms); i++) {
		struct room *r = array_get(rooms, i);
		region reg = maze_new_region(m);

		for (size_t y = r->min.y; y < r->max.y; y++) {
			for (size_t x = r->min.x; x < r->max.x; x++) {
				maze_set_cell(m, (struct pt){x, y}, CLEAR);
				maze_set_region(m, (struct pt){x, y}, reg);
			}
		}
	}

	array_free(rooms, (elem_free)room_free);
}

static void
carve_maze_part(struct maze *m, struct pt from, region reg) {
	struct array *frontier = array_create(10);
	struct pt *f = malloc(sizeof(struct pt));
	f->x = from.x;
	f->y = from.y;
	array_insert(frontier, f);
	
	if (maze_cell_at(m, from) != CLEAR) {
		maze_set_cell(m, from, CLEAR);
		maze_set_region(m, from, reg);
	}

	while (!array_empty(frontier)) {
		struct pt *curr = (struct pt *)array_pick(frontier);
		struct array *unmade = array_create(4);

		for (int i = 0; i < nitems(DIRS); i++) {
			enum dir *d = (enum dir *)&DIRS[i];
			if (can_carve(m, *curr, *d))
				array_insert(unmade, d);
		}

		if (!array_empty(unmade)) {
			enum dir d = *(enum dir *)array_pick(unmade);

			struct pt wall = pt_add_dir(*curr, d);
			struct pt *beyond = pt_add_dir_p(wall, d);

			maze_set_cell(m, wall, CLEAR);
			maze_set_region(m, wall, reg);
			maze_set_cell(m, *beyond, CLEAR);
			maze_set_region(m, *beyond, reg);

			array_insert(frontier, beyond);
		} else {
			array_remove_elems(frontier, curr, (elem_eq)pt_eq_p);
			free(curr);
		}
	}

	array_free(frontier, NULL);
}

static void
carve_connections(struct maze *m, size_t n) {
	/*
		1. Find all cells connecting different regions.
		2. Carve out n of them:
			1. Clear the cell.
			2. Join the neighbouring regions into one region.
	*/
	
	struct array *cs = array_create(50);
	
	/* 1. */
	
	for (size_t y = 2; y < m->height - 1; y += 2) {
		for (size_t x = 2; x < m->width - 1; x += 2) {
			struct pt here = (struct pt){x, y};
						
			if (maze_cell_at(m, here) != WALL)
				continue;
		
			struct pt up = (struct pt){x, y - 1};
			struct pt right = (struct pt){x + 1, y};
			struct pt down = (struct pt){x, y + 1};
			struct pt left = (struct pt){x - 1, y};
			
			bool lr = maze_cell_at(m, left) == CLEAR && maze_cell_at(m, right) == CLEAR &&
				maze_region_at(m, left) != maze_region_at(m, right);
			bool ud = maze_cell_at(m, up) == CLEAR && maze_cell_at(m, down) == CLEAR &&
				maze_region_at(m, up) != maze_region_at(m, down);
			
			if (lr || ud) {
				array_insert(cs, pt_create(x, y));

				if (lr) maze_join_regions(m, left, right);
				if (ud) maze_join_regions(m, up, down);
			}
		}
	}
	
	/* 2. */
	
	int cs_to_carve = min(n, array_size(cs));
		
	for (size_t i = 0; i < cs_to_carve; i++) {
		struct pt *p = array_pick(cs);
		array_remove_elems(cs, p, (elem_eq)pt_eq);
		maze_set_cell(m, *p, ATTENTION);
		free(p);
	}
		
	array_free(cs, (elem_free)free); /* cs has elements left over if n < size(cs). */
}

static bool
can_carve(const struct maze *m, struct pt po, enum dir d) {
	/* Is the next cell in that direction something we can carve? */
	struct pt to = pt_add_dir(pt_add_dir(po, d), d);

	if (to.x < 0 || to. y < 0 || to.x >= m->width || to.y >= m->height)
		return false;

	if (maze_cell_at(m, to) != WALL)
		return false;

	/* Would carving that cell cause a hole next to an edge? */
	struct pt beyond = pt_add_dir(to, d);

	if (beyond.x >= m->width) return false;
	if (beyond.y >= m->height) return false;

	return true;
}
