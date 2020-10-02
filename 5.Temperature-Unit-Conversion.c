#include <stdio.h>

int main(void) {
	double origin_temperture, conv_temperture;
	char unit; // c, C, f, F
	printf("Enter the Temperture: ");
	scanf("%lf%c", &origin_temperture, &unit);
	printf("%0.2lf%c\n", origin_temperture, unit);

	if(unit == 'c' || unit == 'C'){
		conv_temperture = origin_temperture*9/5 + 32;
		printf("Fahrenheit: %0.3lfF\n", conv_temperture);
	}
	else if(unit == 'f' || unit == 'F'){
		conv_temperture = (origin_temperture-32)*5/9;
		printf("Celsius: %0.4lfC\n", conv_temperture);
	}
	else printf("ERROR!\n"); // not temperture unit
	return 0;
}
