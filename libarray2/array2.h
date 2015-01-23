#ifndef _LIBARRAY2_H_
#define _LIBARRAY2_H_

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../libcross/reallocarray.h"

#define DECLARE_ARRAY(_t, _n) \
\
struct _n { \
	size_t size, cap; \
	_t *elems; \
}; \
\
typedef bool (* _n##_elem_eq)(_t, _t); \
typedef void (*_n##_elem_free)(_t *); \
\
struct _n * \
_n##_create(size_t n) { \
	struct _n *o = malloc(sizeof(struct _n)); \
	o->cap = n; \
	o->size = 0; \
	o->elems = calloc(n, sizeof(_t)); \
	return o; \
} \
\
void \
_n##_free(struct _n *o, _n##_elem_free f) { \
	for (size_t i = 0; i < o->size; i++) \
		f(&o->elems[i]); \
	free(o); \
} \
\
size_t \
_n##_size(const struct _n *o) { \
	return o->size; \
} \
\
_t \
_n##_get(const struct _n *o, size_t i) { \
	assert(i < o->size); \
	return o->elems[i]; \
} \
\
void \
_n##_grow(struct _n *a) { \
	assert(a->size == a->cap); \
	size_t grow_to = a->cap * 2; \
	a->elems = reallocarray(a->elems, grow_to, sizeof(struct _n)); \
	a->cap = grow_to; \
} \
\
void \
_n##_add(struct _n *o, _t elem) { \
	if (o->size == o->cap) \
		_n##_grow(o); \
	o->elems[o->size++] = elem; \
} \
\
bool \
_n##_empty(struct _n *a) { \
	return a->size == 0; \
} \
\
void \
_n##_remove(struct _n *a, size_t i) { \
	assert(i < a->size); \
	for (; i < a->size - 1; i++) \
		a->elems[i] = a->elems[i + 1]; \
	a->size--; \
} \
\
size_t \
_n##_remove_elems(struct _n *a, _t el, const _n##_elem_eq eq) { \
	size_t n = 0; \
	for (size_t i = 0; i < a->size; i++) \
		if (eq(el, a->elems[i])) \
			_n##_remove(a, i); \
	return n; \
} \
\
_t \
_n##_pick(const struct _n *a) { \
	return a->elems[arc4random_uniform(a->size)]; \
}

#endif

