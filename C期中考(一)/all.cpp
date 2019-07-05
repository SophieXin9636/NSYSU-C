#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

int p2();
void p3();
void p4();
int p5();
int p6();
int p7();

int p2(){
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
}

void p3(){
	int a[5];
	cout << "Enter five integers:";
	for(int i=0; i<5; i++){
		cin >> a[i];
	}
	sort(a, a+5);
	
	cout << endl;
	cout << "Largest is " << a[4] << endl;
	cout << "Second largest is " << a[3] << endl;
}

void p4(){
	int i, j;
	for(i=1; i<=9; i++){
		for(j=1; j<=9; j++){
			printf("%d*%d=%d\t", j, i, i*j);
		}
		printf("\n");
	}
}

int p5(){
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

int p6(){
	unsigned int x, y; // input

	while(scanf("%d %d", &x, &y)!= EOF){
		int check = 0; // check number of carry
		int carry = 0; // carry or not carry, 0 is not carry
		if(x == -1 || y == -1) return 0;
		if(x >= 1000000000 || y >= 1000000000) return 0; 
		
		int temp_x, temp_y;
		while((x+y+check) >= 10){
			temp_x = x % 10;
			temp_y = y % 10;

			if(carry == 1){
				if((temp_x + temp_y + 1) >= 10){
					check++;				
					carry = 1;
				}
				else carry = 0;
			}
			else{
				if((temp_x + temp_y) >= 10){
					check++;				
					carry = 1;
				}
				else carry = 0;
			}

			x /= 10;
			y /= 10;
		}
		if(check > 0)	printf("%d carry operations\n", check);
		else printf("No carry operations\n");
	} 
	
	return 0;
}

int p7(){
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
}

int main(){
	// p1
	printf("Name: ³¯ÁgªY\n");
	printf("Student ID: B063040059\n");
	
	// p2
	p2();
	cout << endl;
	
	// p3
	p3();
	cout << endl;
	
	// p4
	p4();
	cout << endl;
	
	// p5
	p5();
	cout << endl;
	
	// p6
	p6();
	cout << endl;
	
	// p7
	p7();
	
	return 0;
} 
