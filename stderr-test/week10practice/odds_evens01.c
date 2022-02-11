#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int count = 0;

	printf("How many numbers do you want to enter? ");
	scanf("%d", &count);

	int * temperatures = (int *) malloc(count * sizeof(int));

	int evens_count = 0;
	int odds_count = 0;

	for(int i=0; i<count; i++) {
		printf("Enter temp %d: ", i);
		scanf("%d", &(temperatures[i]));
		if (temperatures[i]%2 == 0)
			evens_count++;
		else
			odds_count++;
	}

	int * evens = (int *) malloc(evens_count * sizeof(int));
	int * odds = (int *) malloc(odds_count * sizeof(int));

	// copy values to correct array
	// reset counters to use as indexes
	evens_count = 0;
	odds_count = 0;
	for (int i=0; i<count; i++) {
		if (temperatures[i]%2 == 0) {
			evens[evens_count] = temperatures[i];
			evens_count++;
		}
		else {
			odds[odds_count] = temperatures[i];
			odds_count++;
		}
	}

	// print odds array then evens array
	for(int i=0; i<odds_count-1; i++) {
		printf("%d ", odds[i]);
	}
	printf("%d \n", odds[odds_count-1]);

	for(int i=0; i<evens_count-1; i++) {
		printf("%d ", evens[i]);
	}
	printf("  %d\n", evens[evens_count-1]);
}