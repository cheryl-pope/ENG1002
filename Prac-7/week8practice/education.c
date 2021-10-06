#include <stdio.h>

int main(void) {
	printf("Enter the years of education: ");
	int years;
	scanf("%d", &years);
	if (years >= 0 && years <=7) 
		printf("primary ");
	else if (years >=8 && years <=12)
		printf("Secondary ");
	else if (years >=13)
		printf("Tertiary ");
	printf("level education");
}