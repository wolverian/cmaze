struct array {};

struct array *
array_create(size_t cap);

void
array_free(struct array *a);

void
array_insert(struct array *a, const void *el);

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
