#include <err.h>
#include <errno.h>
#include <locale.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include <unistd.h>
#include <wchar.h>

#include "../libcross/strtonum.h"

#include "geom.h"
#include "maze.h"
#include "carve.h"

void usage();

struct pt parse_geom(char *);

struct room_params parse_rp(char *);

int
main(int argc, char **argv) {
	size_t w, h;

	(void)setlocale(LC_ALL, "");
	
	struct pt size = (struct pt){
		.x = 31,
		.y = 21
	};
	
	struct room_params rp = (struct room_params){
		.min = (struct pt){
			.x = 5,
			.y = 5
		},
		.max = (struct pt){
			.x = 25,
			.y = 15
		}
	};
	
	size_t corridors = 200;
	
	char ch;
	const char *e;
	while ((ch = getopt(argc, argv, "s:r:c:")) != -1) {
		switch (ch){
		case 's':
			size = parse_geom(optarg); 
			break;
		case 'r':
			rp = parse_rp(optarg);
			break;
		case 'c':
			corridors = strtonum(optarg, 0, 1000, &e);
			if (e) usage();
			break;
		default:
			usage();
		}
	}

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

void
usage() {
	puts("maze [-s size] [-r room geometry] [-c corridors]");
	exit(EX_USAGE);
}

struct pt
parse_geom(char *s) {
	return (struct pt){0, 0};
}

struct room_params
parse_rp(char *s) {
	return (struct room_params){
		.min = (struct pt){0, 0},
		.max = (struct pt){0, 0}
	};
}