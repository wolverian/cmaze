typedef bool
(*elem_eq)(void *a, void *b);

struct set *
set_create(elem_eq eq);

void
set_free(struct set *s);

bool
set_is_empty(struct set *s);

void
set_insert(struct set *s, void *e);

void
set_remove(struct set *s, void *e);

bool
set_contains(struct set *s, void *e);

void *
set_pick(struct set *s);
