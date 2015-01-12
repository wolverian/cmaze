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

struct maze *
maze_create(int height, int width) {
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
maze_cell_at(const struct maze *m, int x, int y) {
	if (x >= m->width) {
		errno = EDOM;
		err(EX_SOFTWARE, "x out of bounds: %d", x);
	}
	if (y >= m->height) {
		errno = EDOM;
		err(EX_SOFTWARE, "y out of bounds: %d", y);
	}

	return m->a[y*m->width + x];
}

void
maze_set_cell(const struct maze *m, int x, int y, cell c) {
	if (x >= m->width) {
		errno = EDOM;
		err(EX_SOFTWARE, "x out of bounds: %d", x);
	}
	if (y >= m->height) {
		errno = EDOM;
		err(EX_SOFTWARE, "y out of bounds: %d", y);
	}
	
	m->a[y*m->width + x] = c;
}

char
cell_str(cell c) {
	switch (c) {
		case 0: return '#';
		case 1: return '.';
	}
	errx(EX_SOFTWARE, "invalid cell");
	// not reached
	return 0;
}

enum dir { UP, RIGHT, DOWN, LEFT };

struct pt {
	int x, y;
};

bool
pt_eq(const struct pt *a, const struct pt *b) {
	return a->x == b->x && a->y == b->y;
}

struct pt *
pt_create(int x, int y) {
	struct pt *p = malloc(sizeof(struct pt));
	p->x = x;
	p->y = y;
	return p;
}

struct pt *
pt_add_dir(const struct pt *p, enum dir d) {
	int x = p->x;
	int y = p->y;
	switch (d) {
		case UP: y -= 1; break;
		case RIGHT: x += 1; break;
		case DOWN: y += 1; break;
		case LEFT: x -= 1; break;
	}
	return pt_create(x, y);
}

void
pt_add_dir_inplace(struct pt *p, enum dir d) {
	switch (d) {
		case UP: p->y -= 1; break;
		case RIGHT: p->x += 1; break;
		case DOWN: p->y += 1; break;
		case LEFT: p->y -= 1; break;
	}
}

bool
can_carve(const struct maze *m, const struct pt *po, enum dir d) {
	struct pt *p = pt_add_dir(po, d);
	pt_add_dir_inplace(p, d);

	if (p->x < 0 || p-> y < 0 || p->x >= m->width || p->y >= m->height)
		return false;

	if (maze_cell_at(m, p->x, p->y) != WALL)
		return false;

	pt_add_dir_inplace(p, d);

	if (p->x >= m->width) return false;
	if (p->y >= m->height) return false;

	return true;
}

void
carve_maze_part(struct maze *m, int x, int y) {
	struct array *frontier = array_create(10);
	array_insert(frontier, &(struct pt){x, y});
}

void
carve_maze(struct maze *m) {
	/* Q: Why do we carve in a loop?
	   A: The carving algorithm can trap itself, i.e. it is not guaranteed
	   to fill the available space. We can brute force around this by
	   carving a maze from every point (x, y) where x and y are both odd.
	   This ensures that the maze is filled as much as possible and that
	   only odd points are carved. */
	for (int y = 1; y < m->height; y += 2) {
		for (int x = 1; x < m->width; x += 2) {
			carve_maze_part(m, x, y);
		}
	}
}

int
main(int argc, char **argv) {
	int w, h;

	if (argc == 2) {
		const char *e;
		long long x = strtonum(argv[1], 0, 400, &e);
		if (e) {
			errno = EDOM;
			err(EX_USAGE, "size must 0-400");
		}
		w = x;
		h = x;
	} else {
		errx(EX_USAGE, "usage: %s size", argv[0]);
	}

	struct maze *m = maze_create(w, h);

	carve_maze(m);

	for (int y = 0; y < m->height; y++) {
		for (int x = 0; x < m->width; x++) {
			putchar(cell_str(maze_cell_at(m, x, y)));
		}
		puts("");
	}

	maze_free(m);
	return 0;
}
