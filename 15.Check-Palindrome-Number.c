#include <stdio.h>

int main(){
	int n;
	int integer;
	int i;
	printf("Enter a positive integer of at most 8:");
	
	while(scanf("%d", &n)!=EOF){
		int a[n];
		if(n>8 || n<0) return 0;
		
		printf("Enter a %d-digit positive integer:", n);
		scanf("%d", &integer);
		if(integer<0) return 0;
		
		int temp = integer;
		for(i=n-1; i>=0; i--){
			a[i] = temp % 10;
			temp /= 10;
		}
				
		int check = 0;
		for(i=0; i<n/2; i++){
			if(a[i] == a[n-i-1])
				check++;
		}
		if(check==n/2) printf("%d is a palindrome.\n", integer);
		else printf("%d is not a palindrome.\n", integer);
		
		printf("Enter a positive integer of at most 8:");
	}
	return 0;
}
