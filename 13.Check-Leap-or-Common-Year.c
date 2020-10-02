#include <stdio.h>

int main(){
	int year;
	
	printf("Enter a year: ");
	while(scanf("%d", &year) != EOF){
		if(year == -1) return 0;
		if((year % 4 == 0) && (year % 100 != 0 )|| (year % 400 == 0))
			printf("Year %d is leap year.\n", year);
		else
			printf("Year %d is common year.\n", year);
		printf("Enter a year: ");
	}
	return 0;
} 
