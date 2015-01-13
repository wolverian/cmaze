#ifndef _MAZE_H_
#define _MAZE_H_

typedef int cell;

enum celltype { WALL, CLEAR };

struct maze {
	int64_t width, height;
	cell *a;
};

struct maze *
maze_create(size_t width, size_t height);

void
maze_free(struct maze *m);

cell
maze_cell_at(const struct maze *m, struct pt p);

void
maze_set_cell(const struct maze *m, struct pt at, cell c);

char
cell_str(cell c);

#endif
