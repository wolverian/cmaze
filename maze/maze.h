#ifndef _MAZE_H_
#define _MAZE_H_

enum cell { WALL, CLEAR, ATTENTION };

typedef int region;

struct maze {
	int64_t width, height;
	int32_t region_counter;
	enum cell *a;
	region *r;
};

struct maze *
maze_create(size_t, size_t);

void
maze_free(struct maze *);

enum cell
maze_cell_at(const struct maze *, struct pt);

void
maze_set_cell(struct maze *, struct pt, enum cell);

void
maze_set_region(struct maze *, struct pt, region);

region
maze_region_at(const struct maze *, struct pt);

region
maze_new_region(struct maze *);

void
maze_join_regions(struct maze *m, struct pt a, struct pt b);

char
cell_str(enum cell c);

#endif
