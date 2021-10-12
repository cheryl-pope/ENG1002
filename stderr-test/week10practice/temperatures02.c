#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int size = 5;  // the maximum size of the array
	int count = 0; // the number of values in the array

	// inital array
	float * temperatures = (float *) malloc(size * sizeof(float));

	float input_temp;

	printf("Enter temp: ");
	scanf("%f", &input_temp);

	while (input_temp != -100.0) {
		// check for space
		if (count == size) {
			// get twice as much space!
			size = size*2;
			float * new_space = (float *) malloc(size * sizeof(float));

			// copy values to new space
			for (int i=0; i<count; i++) {
				new_space[i] = temperatures[i];
			}

			// free the old memory
			free(temperatures);

			// set our temperatures variable to refer to the new space
			temperatures = new_space;
		}

		// add the value to our array
		temperatures[count] = input_temp;
		count++;

		// get the next temperature
		printf("Enter temp: ");
		scanf("%f", &input_temp);
	}

	// print in reverse
	for(int i=count-1; i>0; i--) {
		printf("%.1f ", temperatures[i]);
	}
	printf("%.1f\n", temperatures[0]);
}