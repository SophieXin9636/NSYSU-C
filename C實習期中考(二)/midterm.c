#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct student{
	int ID;
	int score[8];
	int avg;
};

void Question1();
void Question2();
void Question3();
void sorting(int *a, int n);
void sortstud(struct student *ar);
void Question4();
void Question5();
void Question6();
int reverse(int number);


void Question1(){
	printf("Name: 陳縵欣\n");
	printf("Student ID: B063040059\n");
}

void Question2(){
	FILE *in = fopen("input3.txt", "r");
	FILE *out = fopen("input4.txt", "w");
	int ID; // 座號
	int n; // 題數
	int k;
	for(k=0; k<40; k++){
		fscanf(in,"%d", &ID);
		fprintf(out, "%d ", ID);
		int i, j;
		int score;
		for(i=0; i<8; i++){
			fscanf(in,"%d", &n);
			int sum = 0, avg = 0;
			for(j=0; j<n; j++){
				fscanf(in, "%d", &score);
				if(score == -2 || score == -1){
					if(i!=7) fprintf(out, "%d:", score);
					else fprintf(out, "%d\n", score);
					break;
				}
				else sum += score;
			}
			if(score != -2 && score != -1){
				avg = sum / n;
				if(i!=7) fprintf(out, "%d:", avg);
				else fprintf(out, "%d\n", avg);
			}
		}
	}
	fclose(in);
	fclose(out);
}

void Question3(){
	FILE *in = fopen("input4.txt", "r");
	printf("Ranking			ID		Score\n\n");
	
	int i, j;
	struct student stu[41] = {0};
	for(i=1; i<=40; i++){
		int score[8];
		int check = 0; // 檢查是否抄襲，0為沒有抄襲 
		int sum = 0;
		fscanf(in,"%d", &stu[i].ID);
		for(j=0; j<8; j++){
			// 抄襲: -2 缺交: -1 
			fscanf(in, "%d:", &stu[i].score[j]);
			if(stu[i].score[j] == -2){
				check = 1;
				stu[i].score[j] = 0;
			}
			else if(stu[i].score[j] == -1) stu[i].score[j] = 0;
		}
		sorting(score, 8);
		if(check == 1){
			stu[i].avg = (stu[i].score[7] + stu[i].score[6] + stu[i].score[5] + stu[i].score[4] + stu[i].score[3])/5;
		}
		else{
			stu[i].avg = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2] + stu[i].score[3] + stu[i].score[4])/5;
		}
	}
	sortstud(stu);
	int d = 100 - stu[1].avg; // 差值 
	for(i=1; i<=40; i++){
		printf("NO.%d			%d		%d\n", i, stu[i].ID, stu[i].avg+d);
	}

}

void sortstud(struct student *ar){
	int i, j;
	int n = 41;
	for(i=1; i<n; i++){
		for(j=1; j<n-1; j++){
			if(ar[j].avg < ar[j+1].avg){
				struct student temp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = temp;
			}
		}
	}
}

void sorting(int *a, int n){
	int i, j;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-1-i; j++){
			if(a[j]<a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

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

void Question5(){
	int Z, I, M, L;
	int cycle[9999] = {0};
	int testcase=1;
	
	while(1){
		int cycle[9999] = {0};
		scanf("%d%d%d%d", &Z, &I, &M, &L); // 7 5 12 4
		if(M < L) return;
		if(Z==0 && I==0 && M==0 && L==0) return;
		
		int cycle_length = 0;
		int NRN = L;
		cycle[L] = 1;
		while(1){
			cycle_length++;
			NRN = (Z*NRN+I) % M;
			if(L == NRN) break;
			if(cycle[NRN] == 1){
				cycle_length--;
				break;
			}
			else cycle[NRN] = 1;
		}
		
		printf("Case %d: %d\n", testcase, cycle_length);
		testcase++;
	}
}

// 迴文 
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
	srand(time(NULL));
	int i;
	while(1){
		printf("Please enter the number of question(0 for exit): ");
		scanf("%d", &i);
		
		if(i==0) break;
		
		switch(i){
			case 1: Question1(); break;
			case 2: Question2(); break;
			case 3: Question3(); break;
			case 4: Question4(); break;
			case 5: Question5(); break;
			case 6: Question6(); break;
			default:
				printf("Undefined number!!");
		}
	}
	
	return 0;
}
