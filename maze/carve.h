#ifndef _CARVE_H_
#define _CARVE_H_

struct room_params {
	struct pt min, max;
};

void
carve_maze(struct maze *m);

#endif
