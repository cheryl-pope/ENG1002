#include <stdlib.h>

int values_under_100(int * numbers, int count, int ** update_address) {
	int under_100 = 0;
	for (int i=0; i<count; i++) {
		if (numbers[i] < 100)
			under_100++;
	}

	// allocate space
	int * under_100_numbers = (int *) malloc (sizeof(int)*under_100);

	// copy values into new array
	int u100_index = 0;
	for (int i=0; i<count; i++) {
		if (numbers[i] < 100) {
			under_100_numbers[u100_index] = numbers[i];
			u100_index++;
		}
	}
	*update_address = under_100_numbers;

	return under_100;
}