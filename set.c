#include <stdbool.h>
#include <stdlib.h>

#include "set.h"

struct set {
	elem_eq eq;
	void *elems;
};

struct set *
set_create(elem_eq eq) {
	struct set *s = malloc(sizeof(struct set));
	s->eq = eq;
	s->elems = reallocarray(NULL, 0L, sizeof(void *));
	return s;
}

void
set_free(struct set *s) {
	free(s->elems);
	free(s);
}

bool
set_is_empty(const struct set *s) {
	return true;
}

void
set_insert(struct set *s, void *e) {
}

void
set_remove(struct set *s, void *e) {
}

bool
set_contains(const struct set *s, void *e) {
	return false;
}

void *
set_pick(const struct set *s) {
	return NULL;
}
