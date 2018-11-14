#include <stdio.h>

int check_range(int input);
void draw_parallelogram(int input);
void draw_diamond(int input);

int check_range(int input){
	if(input<1 || input>26){
		return 0;
	}
	return 1;
}

void draw_parallelogram(int input){
	for(int i=1; i<=input; i++){
		char symbol ='A';
		for(int j=1; j<i; j++) printf(" ");
		for(int j=1; j<=input; j++, symbol++) printf("%c ", symbol);
		symbol -= 2;
		for(int j=1; j<input; j++, symbol--) printf("%c ", symbol);
		printf("\n");
	}
}

void draw_diamond(int input){
	for(int i=1; i<=input; i++){
		char symbol ='A';
		for(int j=1; j<=input-i; j++) printf("  ");
		for(int j=1; j<=i; j++, symbol++) printf("%c ", symbol);
		symbol -= 2;
		for(int j=2; j<=i; j++, symbol--) printf("%c ", symbol);
		printf("\n");
	}
	for(int i=input-1; i>=1; i--){
		char symbol ='A';
		for(int j=i; j<=input-1; j++) printf("  ");
		for(int j=i; j>0; j--, symbol++) printf("%c ", symbol);
		symbol -= 2;
		for(int j=i; j>1; j--, symbol--) printf("%c ", symbol);
		printf("\n");
	}
}

int main(void) {
	int n;
	printf("Please input the number N: ");
	scanf("%d", &n);

	/* out of range */
	while(!check_range(n)){
		printf("The number N is out of range. Please input again!!\n");
		printf("Please input the number N: \n");
		scanf("%d", &n);
	}
	draw_parallelogram(n);
	printf("\n");
	draw_diamond(n);
	return 0;
}

