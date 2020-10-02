#include <stdio.h>

int main(void) {
	char c; // symbol character
	scanf("%c", &c); // input symbol

	printf("%12c\n", c); //1
	printf("%11c%c%c\n", c, c, c); //3
	printf("%8c%c%c%c%c%c%c%c%c\n", c, c, c, c, c, c, c, c, c); //9
	printf("%10c%c%c%c%c\n", c, c, c, c, c); //5
	printf("%8c%c%c%c%c%c%c%c%c\n", c, c, c, c, c, c, c, c, c); //9
	printf("%6c%c%c%c%c%c%c%c%c%c%c%c%c\n", c, c, c, c, c, c, c, c, c, c, c, c, c); //13
	printf("%10c%c%c%c%c\n", c, c, c, c, c); //5
	printf("%10c%c%c%c%c\n", c, c, c, c, c); //5

	return 0;
}
