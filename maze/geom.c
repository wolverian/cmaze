#include <stdlib.h>
#include <stdbool.h>

#include "geom.h"

const enum dir DIRS[] = {UP, RIGHT, DOWN, LEFT};

bool
pt_eq(struct pt a, struct pt b) {
	return a.x == b.x && a.y == b.y;
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



