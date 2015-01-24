#ifndef _GEOM_H_
#define _GEOM_H_

enum dir {UP, RIGHT, DOWN, LEFT};

const enum dir DIRS[4];

struct pt {
	int x, y;
};

bool pt_eq(struct pt a, struct pt b);

struct pt pt_add_dir(struct pt p, enum dir d);

#endif
