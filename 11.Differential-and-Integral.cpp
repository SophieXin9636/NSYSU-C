#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
using namespace std;

// 這一次的目標主要是以上四個函式的部分，
// 如果圖形x區間顯示的有誤差不會有問題，但是不能不畫圖形。

double g(double);
double d_f(double);
double i_f(double);
void Differential_1(int);
void Differential_2(int);
void Integral_1(int,int);
void Integral_2(int,int);

double a, b, c, d, e, f; // global variable

int main() {

	cout <<"請輸入6個係數: "; // 0 0 0 2 0 0
	cin >> a >> b >> c >> d >> e >> f;

	int x1, x2;
	cout <<"請輸入x軸範圍: "; // 1 2
	cin >> x1 >> x2;
	
	int Px;
	cout <<"請輸入所求切點的x值: ";
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
	// 傳入切點P，對P點做微分逼近
	// 每一次地逼近都必須把結果印出到螢幕上
	printf("使用導數微分計算的結果\n");
	for(double i=0.1; i>=0.01; i-=0.01){
		double result = (g(p+i)-g(p))/i;
		printf("x變化量= %lf，結果為： %lf\n", i, result);
	}
}

void Differential_2(int p){
	// P: tangent point
	
	// implement Differential to P
	// 傳入切點P，對P點做微分，最後將微分結果印出到螢幕上
	double d = d_f(p); // Differential
	printf("使用微分計算的結果為： %lf\n", d);
}

void Integral_1(int x1, int x2){
	// 傳入x的區間x1、x2，使用極小值的方式，
	// 對該區間做積分的逼近，Δx的區間為for(i=0.1; i>=0.01; i-=0.01)，
	// 每一次地逼近都必須把結果印出到螢幕上。
	printf("使用黎曼和計算的結果\n");
	double integral;
	for(double i=0.1; i>=0.01; i-=0.01){
		double sum = 0.0;
		for(double j=x1; j<=x2; j+=i){
			sum += i*g(j);
		}
		printf("x變化量= %lf，結果為： %lf\n", i, sum);
	}
}

void Integral_2(int x1, int x2){
	// 傳入x的區間x1、x2，對該區間坐定積分，最後將結果印到螢幕上。
	double integral = i_f(x2) - i_f(x1);
	printf("使用積分計算的結果為： %lf\n", integral);
}
