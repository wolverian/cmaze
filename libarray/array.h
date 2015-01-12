struct array {};

struct array *
array_create(size_t cap);

void
array_free(struct array *a);

void
array_insert(struct array *a, const void *el);

void *
array_get(const struct array *a, size_t i);
