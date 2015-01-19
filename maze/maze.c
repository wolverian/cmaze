#include <err.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <sysexits.h>

#include "../libcross/reallocarray.h"

#include "geom.h"
#include "maze.h"

struct maze *
maze_create(size_t width, size_t height) {
	if (height > 0 && height > INT64_MAX / width) {
		errno = ENOMEM;
		err(EX_SOFTWARE, "overflow");
	}

	struct maze *m = malloc(sizeof(struct maze));

	m->width = width;
	m->height = height;
	m->region_counter = 0;
	m->a = calloc(width*height, sizeof(enum cell));
	m->r = calloc(width*height, sizeof(region));
	
	return m;
}

void
maze_free(struct maze *m) {
	free(m->a);
	free(m->r);
	free(m);
}

enum cell
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
maze_set_cell(struct maze *m, struct pt at, enum cell c) {
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

void
maze_set_region(struct maze *m, struct pt at, region r) {
	m->r[at.y*m->width + at.x] = r;
}

region
maze_new_region(struct maze *m) {
	return m->region_counter++;
}

char
cell_str(enum cell c) {
	switch (c) {
		case 0: return '#';
		case 1: return ' ';
	}
	errx(EX_SOFTWARE, "invalid cell: %d", c);
}
