#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
using namespace std;

// �o�@�����ؼХD�n�O�H�W�|�Ө禡�������A
// �p�G�ϧ�x�϶���ܪ����~�t���|�����D�A���O���ण�e�ϧΡC

double g(double);
double d_f(double);
double i_f(double);
void Differential_1(int);
void Differential_2(int);
void Integral_1(int,int);
void Integral_2(int,int);

double a, b, c, d, e, f; // global variable

int main() {

	cout <<"�п�J6�ӫY��: "; // 0 0 0 2 0 0
	cin >> a >> b >> c >> d >> e >> f;

	int x1, x2;
	cout <<"�п�Jx�b�d��: "; // 1 2
	cin >> x1 >> x2;
	
	int Px;
	cout <<"�п�J�ҨD���I��x��: ";
	cin >> Px; // 3
	
	for(int x=-10; x<=10; x++){
		double y = a*pow(x,5) + b*pow(x,4) + c*pow(x,3) + d*pow(x,2) + e*x + f; // equation
		
		if(x==0){
			if(x==f) printf("----+----+----+----+----+----+----+----*----+----+----+----+----+----+----+----Y");
			else printf("----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----Y");
		}
		else{
			// use for loop draw a Y-axis scale line
			for(int count = -39; count <= 40; count++){
				if(count == int(y)) printf("*");
				else if(x%5==0 && count == -1 && x < 0){
					printf("%d", x);
					count++;
				}
				else if(count == 0 && x == 5) printf("%d", x);
				else if(count == -1 && x == 10){
					printf("%d", x);
					count++;
				}
				else if(count == 0) printf("|");
				else printf(" ");
			}
		}
		printf("\n");
	}
	
	Differential_1(Px);
	Differential_2(Px);
	Integral_1(x1, x2);
	Integral_2(x1, x2);
	return 0;
}

double g(double x){
	return (a*pow(x,5) + b*pow(x,4) + c*pow(x,3) + d*pow(x,2) + e*x + f); // equation
}

double d_f(double x){
	return (5*a*pow(x,4) + 4*b*pow(x,3) + 3*c*pow(x,2) + 2*d*x + e); // dirrerential equation
}

double i_f(double x){
	return (a*pow(x,6)/6 + b*pow(x,5)/5 + c*pow(x,4)/4 + d*pow(x,3)/3 + e*pow(x,2)/2 + f*x); // integral equation
}

void Differential_1(int p){
	// �ǤJ���IP�A��P�I���L���G��
	// �C�@���a�G�񳣥����⵲�G�L�X��ù��W
	printf("�ϥξɼƷL���p�⪺���G\n");
	for(double i=0.1; i>=0.01; i-=0.01){
		double result = (g(p+i)-g(p))/i;
		printf("x�ܤƶq= %lf�A���G���G %lf\n", i, result);
	}
}

void Differential_2(int p){
	// P: tangent point
	
	// implement Differential to P
	// �ǤJ���IP�A��P�I���L���A�̫�N�L�����G�L�X��ù��W
	double d = d_f(p); // Differential
	printf("�ϥηL���p�⪺���G���G %lf\n", d);
}

void Integral_1(int x1, int x2){
	// �ǤJx���϶�x1�Bx2�A�ϥη��p�Ȫ��覡�A
	// ��Ӱ϶����n�����G��A�Gx���϶���for(i=0.1; i>=0.01; i-=0.01)�A
	// �C�@���a�G�񳣥����⵲�G�L�X��ù��W�C
	printf("�ϥξ��ҩM�p�⪺���G\n");
	double integral;
	for(double i=0.1; i>=0.01; i-=0.01){
		double sum = 0.0;
		for(double j=x1; j<=x2; j+=i){
			sum += i*g(j);
		}
		printf("x�ܤƶq= %lf�A���G���G %lf\n", i, sum);
	}
}

void Integral_2(int x1, int x2){
	// �ǤJx���϶�x1�Bx2�A��Ӱ϶����w�n���A�̫�N���G�L��ù��W�C
	double integral = i_f(x2) - i_f(x1);
	printf("�ϥοn���p�⪺���G���G %lf\n", integral);
}
