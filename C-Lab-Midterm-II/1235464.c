#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Question4(){
	int n; // number of test case
	int happyN; // happy number
	scanf("%d", &n);
	
	int i;
	for(i=1; i<=n; i++){
		scanf("%d", &happyN);
		if(happyN > 1000000000) return;
		int check = 0;
		
		int temp = happyN;
		while(1){
			int n = temp;
			int sum = 0;
			while(n >= 10){
				sum += (n % 10) * (n % 10);
				n /= 10;
			}
			sum += n * n;
			if(sum == 1){
				check = 1;
				break;
			}
			if(sum == happyN){
				check = 0;
				break;
			}
			temp = sum;
		}
		
		printf("Case #%d: ", i);
		if(check == 1)	printf("%d is a Happy number.\n", happyN);
		else printf("%d is an Unhappy number.\n", happyN);
	}
}

int main(){
	Question4();
	return 0;
}
