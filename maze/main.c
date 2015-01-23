#include <err.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include <wchar.h>
#include <locale.h>

#include "../libcross/strtonum.h"

#include "geom.h"
#include "maze.h"
#include "carve.h"

int
main(int argc, char **argv) {
	size_t w, h;

	(void)setlocale(LC_ALL, "");

	if (argc == 2) {
		const char *e;
		long long x = strtonum(argv[1], 1, 400, &e);
		if (e) {
			errno = EDOM;
			err(EX_USAGE, "size must 1-400");
		}
		w = x;
		h = x;
	} else if (argc == 3) {
		const char *e;
		long long x = strtonum(argv[1], 1, 400, &e);
		if (e) {
			errno = EDOM;
			err(EX_USAGE, "width must 1-400");
		}
		e = NULL;
		long long y = strtonum(argv[2], 1, 400, &e);
		if (e) {
			errno = EDOM;
			err(EX_USAGE, "height must 1-400");
		}
		w = x;
		h = y;
	} else {
		errx(EX_USAGE, "usage: %s size | %s width height", argv[0], argv[0]);
	}

	struct maze *m = maze_create(w, h);

	carve_maze(m);

	for (int y = 0; y < m->height; y++) {
		for (int x = 0; x < m->width; x++) {
			putwchar(cell_str(maze_cell_at(m, (struct pt){x, y})));
		}
		puts("");
	}

	maze_free(m);
	return 0;
}
