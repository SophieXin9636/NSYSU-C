#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Question6(){
	int N; // number of test case,  0<=n<=100 
	int P;
	scanf("%d", &N);
	if(N<0 || N>100) return;
	
	// input
	int i;
	for(i=0; i<N; i++){
		int time = 0; // 計算迴文相加次數
		scanf("%d", &P);
		int n = P;
		while(time < 1000){
			int reverseNumber = reverse(n);
			int sum = n + reverseNumber;
			printf("n = %d, reverseNumber = %d, sum = %d, time = %d\n", n, reverseNumber, sum, time);
			time++;
			if(sum == reverse(sum)){
				printf("%d %d\n", time, sum);
				break;
			}
			n = sum;
		}
	}
	
	return;
}

int reverse(int number){
	int temp = number;
	int sum = 0;
	int i;
	while(temp>=10){
		sum = sum*10 + (temp % 10);
		temp /= 10;
	}
	sum = sum*10 + temp;
	return sum;
}

int main(){
	Question6();
	return 0;
}
