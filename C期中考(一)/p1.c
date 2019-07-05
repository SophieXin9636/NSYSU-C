#include <stdio.h>
#include <math.h>

void p4(){
	int i, j;
	for(i=1; i<=9; i++){
		for(j=1; j<=9; j++){
			printf("%d*%d=%d\t", j, i, i*j);
		}
		printf("\n");
	}
}

void p2(){
	int year;
	printf("Enter a year: ");
	while(scanf("%d", &year) != EOF){
		if(year == -1) return;
		if((year % 4 == 0) && (year % 100 != 0 )|| (year % 400 == 0))
			printf("Year %d is leap year.\n", year);
		else
			printf("Year %d is common year.\n", year);
		printf("Enter a year: ");
	}
}

void p7(){
	int input_int;
	int i, counter;

	printf("Enter an integer between and including 10 and 10000000:");
	scanf("%d", &input_int);
	if(input_int < 10 || input_int > 10000000) return;
	
	printf("Armstrong numbers between and including 10 and %d:\n", input_int);
	
	for(counter = 10; counter <= input_int; counter++){
		int digit[8] = {0};
		int sum = 0;
		int n = 0; // number of digit
		int temp = counter;

		for(i=7; i>=0; i--){
			if(temp == 0) break;
			digit[i] = temp % 10;
			temp /= 10;
			n++;
		}
		
		for(i=7; i>=0; i--){
			sum += pow(digit[i], n);
		}
		
		if(sum == counter) printf("%d\n", counter);
	}
}

int main(){
	// p1
	printf("Name: ³¯ÁgªY\n");
	printf("Student ID: B063040059\n");
	
	//p2
	p2();
	
	// p4
	p4();
	
	// p7
	p7();
	
	return 0;
} 
