#include <stdio.h>

int main(void) {
	printf("Enter the temperature in Celcius: ");
	float celcius;
	scanf("%f", &celcius);

	float fahrenheit = celcius * 9 / 5 + 32;

	printf("%.0f degrees Celsius is %.0f degrees Fahrenheit\n", celcius, fahrenheit);
}