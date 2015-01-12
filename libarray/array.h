#ifndef _ARRAY_H_
#define _ARRAY_H_

struct array;

typedef bool (*elem_eq)(const void *a, const void *b);

struct array *
array_create(size_t cap);

void
array_free(struct array *a);

void
array_insert(struct array *a, void *el);

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
array_contains(const struct array *a, void *el, const elem_eq eq);

#endif
