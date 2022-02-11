#include "q3f.c"
#include <stdlib.h>
#include <stdio.h>

int main(void) {

	int * under_100_array;

	int count;
	scanf("%d", &count);

	int * numbers = (int *) malloc (count * sizeof(int));

	for (int i=0; i<count; i++)
		scanf("%d", &numbers[i]);

	int under_100_count = values_under_100(numbers, count, &under_100_array);

	printf("%d\n", under_100_count);
	for (int i=0; i<under_100_count; i++) {
		printf("%d", under_100_array[i]);
	}
	printf("\n");
}