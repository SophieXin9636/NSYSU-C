#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

void Question1();
void Question2();
void Question3();
void Question4();
void Question5();

// Q1
void Question1(){
	printf("Name: ³¯ÁgªY\n");
	printf("Student ID: B063040059\n");
}

// Q2 (Done)
void Question2(){
	int d;
	int i,j,k;
	while(1){
		printf("Please input number of digits: ");
		scanf("%d", &d);
		if(d==0) break;
		int digit[8]={0};
		int v = 1;
		for(i=0; i<d; i++) v *= 10;
		for(i=0; i<v; i++){
			int temp = i;
			int a=0, b=0;
			for(j=d-1; j>=0; j--){
				digit[j] = temp%10;
				temp /= 10;
			}
			for(j=0; j<d/2; j++){
				a *= 10;
				a += digit[j];
			}
			for(j=d/2; j<d; j++){
				b *= 10;
				b += digit[j];
			}
			//printf("%d %d %d\n", a, b, i);
			if( (a+b)*(a+b) == i ){
				for(j=0; j<d; j++)	printf("%d", digit[j]);
				printf("\n");
			}
		}
	}
}

// Q3 (Done)
void Question3(){
	char str[21];
	int prime[123];
	int i=0;
	for(i=0; i<123; i++){
		prime[i] = 0;
	}
	int value = 27;
	for(i=65; i<=90; i++){
		prime[i] = value;
		value++;
	}
	value = 1;
	for(i=97; i<=122; i++){
		prime[i] = value;
		value++;
	}
	
	printf("Please input a string: ");
	while(scanf("%s", str)!=EOF){
		int num = 0;
		for(i=0; i<strlen(str); i++){
			int k = str[i];
			num += prime[k];
		}
		if(checkPrime(num)) printf("It is a prime word.\n");
		else printf("It is not a prime word.\n");
		printf("Please input a string: ");
	}
}

int checkPrime(int n){
	int i, j;
	int check = 0;  // false
	if(n%2 == 0) return 0;
	for(i=3; i*i<n; i+=2){
		if(n%i == 0) return 0;
	}
	return 1;
}

// Q4
struct Node{
	int data;
	struct Node *pre;
	struct Node *next;
}; 
typedef struct Node Node;
Node *tail = NULL;

Node *insert(Node *head, int value){
	// empty
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->pre = NULL;
	newNode->next = NULL;
	newNode->data = value;
	if(head == NULL) return 0;
}

Node *concat(Node *a, Node *b){
	
}

void Question4(){
	int n;
	scanf("%d", &n);
	Node *a = (Node *) malloc(sizeof(Node)*10);
	int i,j;
	/*
	for(i=0; i<n; i++){
		*(a+i)->pre = NULL;
		a[i]->next = NULL;
		a[i]->data = i;
	}*/
	if(n<=0 || n>=25) return;
	char cmd1[5], cmd2[5];
	while(1){
		int n1, n2;
		scanf("%s", &cmd1);
		if(cmd1[0] == 'q') break; // quit
		
		if(cmd1[0] == 'm' || cmd1[0] == 'p'){ // move
			scanf("%d", &n1);
			if(n1 > n || n1 < 0) return;
			scanf("%s", &cmd2);
			if(cmd2[1] == 'n'){ // onto
				scanf("%d", &n2);
				if(n2 > n || n2 < 0) return;
			}
			else if(cmd2[1] == 'v'){ // over
				scanf("%d", &n2);
				if(n2 > n || n2 < 0) return;
			}
		}
	}
}

// Q5 Using stack (Done)
int Isempty(int *t){
	if(*t == 0) return 1;
	return 0;
}

void push(char *s, char data, int *t){
	s[*t] = data;
	//printf("s[*t]=%c, data=%c\n", s[*t], data);
	//strcpy(s[*t], data);
	(*t)++;
}

int pop(char *s, int *t){
	if(*t == 0) return 0;
	s[*t] = NULL;
	free(s[*t]);
	(*t)--;
	return 1;
}

void Question5(){
	int n, i=0,j=0;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		int check = 0;
		char str[128];
		scanf("%s", str);
		char Stack[128] = {};
		int top = 0;
		for(j=0; j<strlen(str); j++){
			if(str[j] == '(' || str[j] == '['){
				//printf("push#\n");
				push(Stack, str[j], &top);
			}
			else if(str[j] == ')' || str[j] == ']'){
				//printf("pop#\n");
				check = pop(Stack, &top);
			}
			//printf("top = %d, stack: %s\n", top, Stack);
		}
		if(Isempty(&top) && check == 1) printf("Yes\n");
		else printf("No\n");
	}
}

int main(){
	srand(time(NULL));
	int i;
	while(1){
		printf("Please enter the number of question(0 for exit): ");
		scanf(" %d", &i);
		if(i == 0) break;
		
		switch(i){
			case 1: Question1(); break;
			case 2: Question2(); break;
			case 3: Question3(); break;
			case 4: Question4(); break;
			case 5: Question5(); break;
			default: printf("Undefined number!!");
		}
	}
}
