#include <stdio.h>

int main(void) {
	printf("Enter your name, age and employment fraction: ");
	char first_name[11];
	char last_name[11];
	int age;
	float employment;
	scanf("%10s %10s %d %f", first_name, last_name, &age, &employment);

	printf("Your name is %s %s, you are %d years old and your employment fraction is %1f\n", first_name, last_name, age, employment);
}