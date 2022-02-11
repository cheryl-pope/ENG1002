#include <stdlib.h>
#include <string.h>

int surprise(char * format, char * array) {
	int number_length=0, i=1;
	while(format[i]!='s') {
		number_length++;
		i++;
	}

	int mult = 1;
	int N = 0;
	for (int i=number_length; i>0; i--) {
		N = N + mult * atoi(&format[i]);
		mult = mult * 10;
	}

	char myString[] = "Surprise!";

	int characters = 0;
	if (strlen(myString) > N)
		characters = N;
	else
		characters = strlen(myString);

	for (i=0; i<characters; i++) {
		array[i] = myString[i];
	}

	array[i] = '\0';

	return characters;
}

#include <stdio.h>

int main(void) { 

  char example_1[20];
  char example_2[20];

  int read_1 = surprise("%4s", example_1);
  int read_2 = surprise("%19s", example_2);

  printf("I copied %d characters: %s and %s", read_1+read_2, example_1, example_2);

  return 0;
}