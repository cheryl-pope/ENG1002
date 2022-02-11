#include "q2.c"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int count;
	scanf("%d", &count);

	int * numbers = (int *) malloc (count * sizeof(int));

	for (int i=0; i<count; i++)
		scanf("%d", &numbers[i]);

	int under_100_count = values_under_100(numbers, count);

	printf("%d", under_100_count);
}