#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Question1();
void Question2();
void Question3();
void Question4();
void Question5();
void Question6();
void selectionSort(int []);
void rank(int grade[40][2]);
int isSame(int);

int main()
{
	srand(time(NULL));
	int i;
	while(1){
		printf("Please enter the number of question(0 for exit): ");
		scanf("%d", &i);
		
		if(i==0) break;
		
		switch(i){
			case 1:
				Question1();
				break;
			case 2:
				Question2();
				break;
			case 3:
				Question3();
				break;
			case 4:
				Question4();
				break;
			case 5:
				Question5();
				break;
			case 6:
				Question6();
				break;
			default:
				printf("Undefined number!!");
		}
	}
}
void Question1()
{
	printf("\n");
	printf("Name: %s\n", "¤ýÅA¶v");
	printf("Student ID: %s\n", "B065040034");
	system("pause");
	printf("\n");
}
void Question2()
{
	int n, t,data[5]={0}, i, j, k, sum;
	FILE *cfPtr1, *cfPtr2;
	cfPtr1=fopen("input3.txt","r");
	cfPtr2=fopen("input4.txt","w");
	for(i=0;i<40;i++){
		fscanf(cfPtr1,"%d", &n);
		fprintf(cfPtr2,"%d ", n);
		for(j=0;j<8;j++){
			fscanf(cfPtr1,"%d", &t);
			fscanf(cfPtr1,"%d", &data[0]);
			sum=0;
			if(data[0]<0){
				fprintf(cfPtr2,"%d", data[0]);
			}
			else{
				sum=data[0];
				for(k=1;k<t;k++){
					fscanf(cfPtr1,"%d", &data[k]);
					sum+=data[k];
				}
				sum/=t;
				fprintf(cfPtr2,"%d", sum);
			}
			if(j!=7)
				fprintf(cfPtr2,":");
		}
		fprintf(cfPtr2,"\n");
	}
	fclose(cfPtr1);
	fclose(cfPtr2);
}
void Question3()
{
	int ID[40][2]={0}, score[8]={0}, i, j, k, flag, max;
	char c;
	FILE *cfPtr;
	cfPtr=fopen("input4.txt","r");
	for(i=0;i<40;i++){
		fscanf(cfPtr,"%d", &ID[i][0]);
		flag=0;
		for(j=0;j<8;j++){
			fscanf(cfPtr,"%d", &score[j]);
			if(score[j]==-1)
				score[j]=0;
			if(score[j]==-2){
				score[j]=0;
				flag=1;
			}
			if(j!=7)
				fscanf(cfPtr,"%c", &c);
		}
		selectionSort(score);
		if(flag==0){
			for(k=0;k<5;k++){
				ID[i][1]+=score[k];
			}
			ID[i][1]/=5;
		}
		else if(flag==1){
			for(k=3;k<8;k++){
				ID[i][1]+=score[k];
			}
			ID[i][1]/=5;
		}
	}
	max=ID[0][1];
	for(k=0;k<40;k++){
		if(ID[k][1]>max)
			max=ID[k][1];
	}
	for(k=0;k<40;k++){
		ID[k][1]+=100-max;
	}
	rank(ID);
	printf("%-18s%-8s%s\n", "Ranking", "ID", "Score");
	printf("\n");
	for(k=0;k<40;k++){
		printf("NO.%-15d%2d%9d\n", k+1, ID[k][0], ID[k][1]);
	}
	printf("\n");
}
void Question4()
{
	int N, x, i, j=0, sum, t;
	scanf("%d", &N);
	int output[N], check[N];
	for(i=0;i<N;i++){
		scanf("%d", &output[i]);
		x=output[i];
		while(x<10)
			x=x*x;
		sum=x;
		while(sum>=10){
			x=sum;
			sum=0;
			while(x>0){
				t=x%10;
				sum+=t*t;
				x/=10;
			}
		}
		if(sum==1){
			check[i]=1;
		}
		else{
			check[i]=0;
		}
	}
	printf("\n");
	for(i=0;i<N;i++)
		if(check[i]==1)
			printf("Case#%d: %d is a Happy number.\n", i+1, output[i]);
		else
			printf("Case#%d: %d is a Unhappy number.\n", i+1, output[i]);
	printf("\n");
}
void Question5()
{
	int Z, I, M, L, i=0, j, next, seed, count;
	int Ans[10000]={0};
	while(scanf("%d%d%d%d", &Z, &I, &M, &L) && (Z!=0 && I!=0 && M!=0 && L!=0)){
		int check[10000]={0};
		count=0;
		seed=L;
		next=(Z*L+I)%M;
		L=next;
		while(check[L]!=1){
			check[L]=1;
			next=(Z*L+I)%M;
			L=next;
			count++;
		}
		Ans[i++]=count;
	}
	printf("\n");
	for(j=0;j<i;j++){
		printf("Case %d: %d\n", j+1, Ans[j]);
	}
}
void Question6()
{
	int n, P, count, i, x, y, z, flag;
	scanf("%d", &n);
	int Ans[n][2];
	for(i=0;i<n;i++){
		scanf("%d", &x);
		y=x;
		z=0;
		count=0;
		flag=0;
		while(!isSame(x) || flag==0){
			flag=1;
			y=x;
			z=0;
			while(y>=10){
				z=(z+(y%10))*10;
				y/=10;
			}
			z+=y;
			x=x+z;
			count++;
		}
		Ans[i][0]=count;
		Ans[i][1]=x;
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%d %d\n", Ans[i][0], Ans[i][1]);
	}
	printf("\n");
}
void selectionSort(int num[])
{
	int max, i, j, temp;
	for(i=0;i<7;i++){
		max=i;
		for(j=i+1;j<8;j++){
			if(num[max]<num[j]){
				max=j;
			}
		}
		temp=num[i];
		num[i]=num[max];
		num[max]=temp;
	}
}
void rank(int grade[40][2])
{
	int max, i, j, temp;
	for(i=0;i<39;i++){
		max=i;
		for(j=i+1;j<40;j++){
			if(grade[max][1]<grade[j][1]){
				max=j;
			}
		}
		temp=grade[i][1];
		grade[i][1]=grade[max][1];
		grade[max][1]=temp;
		temp=grade[i][0];
		grade[i][0]=grade[max][0];
		grade[max][0]=temp;
	}
}
int isSame(int x)
{
	int y, z;
	y=x;
	z=0;
	while(y>=10){
		z=(z+(y%10))*10;
		y/=10;
	}
	z+=y;
	if(x==z)
		return 1;
	else
		return 0;
}
