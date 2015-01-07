typedef int
(*elem_eq)(void *a, void *b);

struct set *
set_create(elem_eq eq);

void
set_free(struct set *s);

int
set_is_empty(struct set *s);

void
set_insert(struct set *s, void *e);

void
set_remove(struct set *s, void *e);

int
set_contains(struct set *s, void *e);

void *
set_pick(struct set *s);
