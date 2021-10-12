#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int count = 0;

	printf("How many temperatures do you want to enter? ");
	scanf("%d", &count);

	float * temperatures = (float *) malloc(count * sizeof(float));

	for(int i=0; i<count; i++) {
		printf("Enter temp %d: ", i);
		scanf("%f", &(temperatures[i]));
	}

	// print in reverse
	for(int i=count-1; i>0; i--) {
		printf("%.1f ", temperatures[i]);
	}
	printf("%.1f\n", temperatures[0]);
}