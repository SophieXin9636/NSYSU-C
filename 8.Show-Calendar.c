#include <stdio.h>

int main(void) {
	int n; // input
	printf("Input: ");
	scanf("%d", &n);
	
	int start, month, year;
	
	start = n % 10;
	if(start > 6 || start < 0) return 0;
	
	month = (n/10)%100;
	if(month > 12 || month <= 0) return 0;
	
	year = n/1000;
	
	int day;
	switch(month){
		case 1 :
			printf("\n                      January, %d\n", year);
			break;
		case 2 :
			printf("\n                     February, %d\n", year);
			break;
		case 3 :
			printf("\n                        March, %d\n", year);
			break;
		case 4 :
			printf("\n                        April, %d\n", year);
			break;
		case 5 :
			printf("\n                          May, %d\n", year);
			break;
		case 6 :
			printf("\n                         June, %d\n", year);
			break;
		case 7 :
			printf("\n                         July, %d\n", year);
			break;
		case 8 :
			printf("\n                       August, %d\n", year);
			break;
		case 9 :
			printf("\n                    September, %d\n", year);
			break;
		case 10 :
			printf("\n                      October, %d\n", year);
			break;
		case 11 :
			printf("\n                     November, %d\n", year);
			break;
		case 12 :
			printf("\n                     December, %d\n", year);
			break;
	}
	printf("  SUN  MON  TUE  WED  THU  FRI  SAT\n");
	
	if(month == 2){
		// check whether year is leap year
		if(year % 4 == 0 && year % 100 != 0) day = 29;
		// not leap year
		else day = 28;
	}
	else{
		switch(month){
			case 1: case 3: case 5: case 7: case 8: case 10:  case 12:
				day = 31;
				break;
			case 4: case 6: case 9: case 11:
				day = 30;
				break;
		}
	}
	// print calender
	char p = ' ';
	int i;
	for(i=0; i<start; i++) printf("%5c", p);
	for(i=1; i<=day; i++){
		if((i+start)%7==0)
			printf("%5d\n", i);
		else printf("%5d", i);
	}
	return 0;
}

