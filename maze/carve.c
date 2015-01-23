#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libcross/nitems.h"
#include "../libarray2/array2.h"

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

struct room {
	struct pt min, max;
};

DECLARE_ARRAY(struct pt, ptarray);
DECLARE_ARRAY(struct room, roomarray);
DECLARE_ARRAY(enum dir, dirarray);

static void
carve_maze_rooms(struct maze *, size_t, struct room_params);

static void
carve_corridors(struct maze *m);

static void
carve_maze_part(struct maze *, struct pt, region reg);

static bool
can_carve(const struct maze *, struct pt, enum dir);

static void
carve_connections(struct maze *m);

static void
uncarve_dead_ends(struct maze *m);

static struct ptarray *
find_connectors(const struct maze *m, size_t extra_conns);

void
carve_maze(struct maze *m) {
	carve_maze_rooms(m, 50, (struct room_params){
		.min = (struct pt){.x = 5, .y = 5},
		.max = (struct pt){.x = 21, .y = 15}
	});
	carve_corridors(m);
	carve_connections(m);
	uncarve_dead_ends(m);
}

void
carve_corridors(struct maze *m) {
	/* Q: Why do we carve in a loop?
	   A: The carving algorithm can trap itself, i.e. it is not guaranteed
	   to fill the available space. We can brute force around this by
	   carving a maze from every point (x, y) where x and y are both odd.
	   This ensures that the maze is filled as much as possible and that
	   only odd points are carved. */
	   
	for (int y = 1; y < m->height - 1; y += 2) {
		for (int x = 1; x < m->width - 1; x += 2) {
			struct pt here = (struct pt){x, y};
			
			if (maze_cell_at(m, here) != CLEAR)	
				carve_maze_part(m, here, maze_new_region(m));
			}
	}
}

static bool
rooms_overlap(struct room a, struct room b) {
	return (a.min.x < b.max.x && a.max.x > b.min.x &&
		a.min.y < b.max.y && a.max.y > b.min.y);
}

static void
carve_maze_rooms(struct maze *m, size_t max_tries, struct room_params rp) {
	struct roomarray *rooms = roomarray_create(10);

	for (size_t i = 0; i < max_tries; i++) {
		/* Is this mess even correct? */
		size_t y = arc4random_uniform(m->height/2)*2 + 1;
		size_t x = arc4random_uniform(m->width/2)*2 + 1;
		size_t height = arc4random_uniform(rp.max.y/2)*2 + rp.min.y;
		size_t width = arc4random_uniform(rp.max.x/2)*2 + rp.min.x;

		struct room r = (struct room){
			.min = (struct pt){x, y},
			.max = (struct pt){x+width, y+height}
		};

		bool overlap = false;

		for (size_t j = 0; j < roomarray_size(rooms); j++) {
			if (rooms_overlap(r, roomarray_get(rooms, j))) {
				overlap = true;
			}
		}

		bool in_bounds = r.max.x < m->width && r.max.y < m->height;

		if (!overlap && in_bounds)
			roomarray_add(rooms, r);
	}

	for (size_t i = 0; i < roomarray_size(rooms); i++) {
		struct room r = roomarray_get(rooms, i);
		region reg = maze_new_region(m);

		for (size_t y = r.min.y; y < r.max.y; y++) {
			for (size_t x = r.min.x; x < r.max.x; x++) {
				maze_set_cell(m, (struct pt){x, y}, CLEAR);
				maze_set_region(m, (struct pt){x, y}, reg);
			}
		}
	}

	roomarray_free(rooms);
}

static void
carve_maze_part(struct maze *m, struct pt from, region reg) {
	struct ptarray *frontier = ptarray_create(10);
	ptarray_add(frontier, from);
	
	if (maze_cell_at(m, from) != CLEAR) {
		maze_set_cell(m, from, CLEAR);
		maze_set_region(m, from, reg);
	}

	while (!ptarray_empty(frontier)) {
		struct pt curr = ptarray_pick(frontier);
		struct dirarray *unmade = dirarray_create(4);

		for (int i = 0; i < nitems(DIRS); i++) {
			if (can_carve(m, curr, DIRS[i]))
				dirarray_add(unmade, DIRS[i]);
		}

		if (!dirarray_empty(unmade)) {
			enum dir d = dirarray_pick(unmade);

			struct pt wall = pt_add_dir(curr, d);
			struct pt beyond = pt_add_dir(wall, d);

			maze_set_cell(m, wall, CLEAR);
			maze_set_region(m, wall, reg);
			maze_set_cell(m, beyond, CLEAR);
			maze_set_region(m, beyond, reg);

			ptarray_add(frontier, beyond);
		} else {
			ptarray_remove_elems(frontier, curr, (ptarray_elem_eq)pt_eq);
		}
	}

	ptarray_free(frontier);
}

static void
carve_connections(struct maze *m) {
	/*
		1. Find a cell connecting two different regions.
		2. Clear the cell.
		3. Join the neighbouring regions into one region.
	*/
		
	while (true) {
		/* 1. */	
		struct ptarray *cs = find_connectors(m, 50);
		
		if (ptarray_empty(cs))
			break;
		
		struct pt p = ptarray_pick(cs);
		ptarray_remove_elems(cs, p, pt_eq);
		
		maze_set_cell(m, p, CLEAR);
				
		struct pt up = pt_add_dir(p, UP);
		struct pt right = pt_add_dir(p, RIGHT);
		struct pt down = pt_add_dir(p, DOWN);
		struct pt left = pt_add_dir(p, LEFT);
	
		bool lr = maze_cell_at(m, left) == CLEAR && maze_cell_at(m, right) == CLEAR;
		bool ud = maze_cell_at(m, up) == CLEAR && maze_cell_at(m, down) == CLEAR;
		
		if (lr && ud) {
			maze_join_regions(m, up, right);
			maze_join_regions(m, right, down);
			maze_join_regions(m, down, left);
		} else if (lr) {
			maze_join_regions(m, left, right);
		} else if (ud) {
			maze_join_regions(m, up, down);
		}
		
		ptarray_free(cs);
	}
}

static struct ptarray *
find_connectors(const struct maze *m, size_t extra_conns) {
	struct ptarray *cs = ptarray_create(50);
	
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
			
			bool clear_lr = maze_cell_at(m, left) == CLEAR && maze_cell_at(m, right) == CLEAR;
			bool lr = clear_lr && maze_region_at(m, left) != maze_region_at(m, right);
			
			bool clear_ud = maze_cell_at(m, up) == CLEAR && maze_cell_at(m, down) == CLEAR;
			bool ud = maze_region_at(m, up) != maze_region_at(m, down);
				
			bool extra = (clear_lr || clear_ud) && arc4random_uniform(extra_conns) == 0;
			
			if (lr || ud)
				ptarray_add(cs, here);
		}
	}
	
	return cs;
}

static bool
is_dead_end(struct maze *m, struct pt p) {
	if (maze_cell_at(m, p) != CLEAR) return false;
	size_t n = maze_cell_at(m, pt_add_dir(p, UP))    != CLEAR ? 1 : 0;
	n       += maze_cell_at(m, pt_add_dir(p, RIGHT)) != CLEAR ? 1 : 0;
	n       += maze_cell_at(m, pt_add_dir(p, DOWN))  != CLEAR ? 1 : 0;
	n       += maze_cell_at(m, pt_add_dir(p, LEFT))  != CLEAR ? 1 : 0;
	return n == 3;
}

static void
uncarve_dead_ends(struct maze *m) {
	size_t n = 200;
	
	while (true) {
		struct ptarray *ds = ptarray_create(50);
		size_t corrs = 0;

		for (size_t y = 1; y < m->height - 1; y++) {
			for (size_t x = 1; x < m->width - 1; x++) {
				struct pt here = (struct pt){x, y};
				
				if (maze_cell_at(m, here) == CLEAR)
					corrs++;
					
				if (is_dead_end(m, here)) {
					ptarray_add(ds, here);
				}
			}
		}
	
		if (corrs <= n || ptarray_empty(ds)) {
			ptarray_free(ds);
			break;
		}
			
		for (int i = 0; i < ptarray_size(ds); i++)
			maze_set_cell(m, ptarray_get(ds, i), WALL);
		
		ptarray_free(ds);
	}
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
