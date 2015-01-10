typedef bool
(*elem_eq)(const void *a, const void *b);

struct set *
set_create(elem_eq eq);

void
set_free(struct set *s);

bool
set_is_empty(const struct set *s);

void
set_insert(struct set *s, void *e);

void
set_remove(struct set *s, void *e);

bool
set_contains(const struct set *s, void *e);

void *
set_pick(const struct set *s);
