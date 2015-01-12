#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "../array.h"

struct pt {
	int x, y;
};

bool
pt_eq(struct pt a, struct pt b) {
	return a.x == b.x && a.y == b.y;
}

void
test_insertion();

void
test_removal();

void
test_contains();

int
main(int argc, char **argv) {
	test_insertion();
	test_removal();
	test_contains();

	return 0;
}

void
test_insertion() {
	struct array *a = array_create(10);
	struct pt p1 = {0, 0};
	struct pt p2 = {3, 5};

	array_insert(a, &p1);
	array_insert(a, &p2);

	assert(!array_empty(a));
	assert(array_get(a, 0) == &p1);
	assert(array_get(a, 1) == &p2);

	free(a);
}

void
test_removal() {
	struct array *a = array_create(10);
	struct pt p1 = {0, 0};
	struct pt p2 = {3, 5};

	array_insert(a, &p1);
	array_insert(a, &p2);

	array_remove(a, 0);
	assert(!array_empty(a));
	assert(array_size(a) == 1);
	assert(array_get(a, 0) == &p2);

	array_insert(a, &p1);
	array_remove(a, 1);
	assert(!array_empty(a));
	assert(array_size(a) == 1);
	assert(array_get(a, 0) == &p2);

	array_remove(a, 0);
	assert(array_empty(a));
	assert(array_size(a) == 0);

	free(a);
}

bool
my_eq(const void *a, const void *b) {
	return pt_eq(*(struct pt *)a, *(struct pt *)b);
}

void
test_contains() {
	struct array *a = array_create(10);
	struct pt p1 = {0, 0};
	struct pt p2 = {3, 5};

	array_insert(a, &p1);
	array_insert(a, &p2);

	assert(array_contains(a, &p1, my_eq));
}
