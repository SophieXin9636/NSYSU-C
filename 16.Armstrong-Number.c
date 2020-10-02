#include <stdio.h>
#include <math.h>

int main(){
	int input_int;
	int i, counter;

	printf("Enter an integer between and including 10 and 10000000:");
	scanf("%d", &input_int);
	if(input_int < 10 || input_int > 10000000) return 0;
	
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
	return 0;
}
