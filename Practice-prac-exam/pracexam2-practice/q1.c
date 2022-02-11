#include <stdio.h>

int main(void) {

	double numbers[10];

	printf("Enter a number: ");
	scanf("%lf", &(numbers[0]));
	
	double max = numbers[0];

	for (int i=1; i<10; i++) {
		printf("Enter a number: ");
		scanf("%lf", &(numbers[i]));
		if (numbers[i] > max)
			max = numbers[i];
	}

	printf("The largest of your numbers is: %.1lf", max);
}