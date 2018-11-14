#include <stdio.h>

// call by address
void swap(int *x, int *y);
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main(void) {
	int a, b, c; // side of triangle
	int i = 0;
	while(i < 10){
		scanf("%d %d %d", &a, &b, &c);
		if(a==b && b==c){
			printf("%d %d %d �i�H�c���T����\n", a, b, c);
			printf("%d %d %d �c���������T����\n", a, b, c);
		}
		// 3 variable sort
		else{
			if(a > b){
				swap(&a, &b);
				if(a > c) swap(&a, &c);
				if(b > c) swap(&b, &c);
			}
			else{ // b > a
				if(a > c) swap(&a, &c);
				if(b > c) swap(&b, &c);
			}

			if((a+b) > c){
				printf("%d %d %d �i�H�c���T����\n", a, b, c);
				if(a==b) printf("%d %d %d �c���������y�T����\n", a, b, c);
				else printf("%d %d %d �c�������@��T����\n", a, b, c);
			}
			else printf("%d %d %d ���i�H�c���T����\n", a, b, c);
		}
		++i;
	}
	return 0;
}
