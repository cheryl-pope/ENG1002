#include <stdio.h>

int main(void) {
	printf("Enter a three digit number: ");
	int number;
	scanf("%d", &number);

	for(int i=0; i<3; i++) {
		printf("%d\n", number%10);
		number = number/10;
	}
}