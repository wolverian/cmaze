#ifndef _ARRAY_H_
#define _ARRAY_H_

struct array;

typedef bool (*elem_eq)(const void *, const void *);
typedef void (*elem_free)(void *);

struct array *
array_create(size_t cap);

void
array_free(struct array *, elem_free f);

void
array_insert(struct array *, void *);

void *
array_get(const struct array *a, size_t i);

size_t
array_size(const struct array *a);

bool
array_empty(const struct array *a);

void *
array_pick(const struct array *a);

void *
array_remove(struct array *a, size_t i);

bool
array_remove_elems(struct array *a, const void *el, const elem_eq eq);

bool
array_contains(const struct array *a, const void *el, const elem_eq eq);

#endif
