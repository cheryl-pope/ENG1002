#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int count;
	scanf("%d", &count);

	int * numbers = (int *) malloc (count * sizeof(int));

	for (int i=0; i<count; i++)
		scanf("%d", &numbers[i]);

	for (int i=0; i<count; i++)
		printf("%d ", numbers[i]);
	printf("\n");
}