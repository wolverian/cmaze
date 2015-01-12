#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "../array.h"

struct pt {
	int x, y;
};

int
main(int argc, char **argv) {
	struct array *a = array_create(10);
	struct pt p1 = {0, 0};
	struct pt p2 = {3, 5};


	// Insertion
	array_insert(a, &p1);
	array_insert(a, &p2);
	assert(array_get(a, 0) == &p1);
	assert(array_get(a, 1) == &p2);


	// Deletion
	array_remove(a, 0);
	assert(array_size(a) == 1);
	assert(array_get(a, 0) == &p2);

	array_insert(a, &p1);
	array_remove(a, 1);
	assert(array_size(a) == 1);
	assert(array_get(a, 0) == &p2);

	array_remove(a, 0);
	assert(array_size(a) == 0);

	array_free(a);
	return 0;
}
