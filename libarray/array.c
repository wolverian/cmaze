#include <stdlib.h>
#include <assert.h>

struct array {
	size_t cap, size;
	void **elems;
};

struct array *
array_create(size_t cap) {
	struct array *a = malloc(sizeof(struct array));
	a->cap = cap;
	a->size = 0;
	a->elems = reallocarray(NULL, cap, sizeof(void *));
	return a;
}

void
array_free(struct array *a) {
	free(a->elems);
	free(a);
}

void
array_grow(struct array *a) {
	assert(a->size == a->cap);
	size_t grow_to = a->cap * 2;
	a->elems = reallocarray(a->elems, grow_to, sizeof(void *));
	a->cap = grow_to;
}

void
array_insert(struct array *a, void *el) {
	if (a->size == a->cap)
		array_grow(a);
	a->elems[a->size] = el;
}

void *
array_get(const struct array *a, size_t i) {
	assert(i < a->size);
	return a->elems[i];
}
