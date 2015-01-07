#include <stdbool.h>
#include <stdlib.h>

#include "set.h"

struct set {
	elem_eq eq;
};

struct set *
set_create(elem_eq eq) {
	struct set *s = malloc(sizeof(struct set));
	s->eq = eq;
	return s;
}

void
set_free(struct set *s) {
	free(s);
}

bool
set_is_empty(struct set *s) {
	return true;
}

void
set_insert(struct set *s, void *e) {
}

void
set_remove(struct set *s, void *e) {
}

bool
set_contains(struct set *s, void *e) {
	return false;
}

void *
set_pick(struct set *s) {
	return NULL;
}
