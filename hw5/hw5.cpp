#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
using namespace std;
const double pi = 3.14159265358979323846;

void print_line(int checkSlope); // prototype
void print_line(int checkSlope){
	if(checkSlope > 0 && checkSlope <= 10) cout << "\\";
	else if(checkSlope >= -10 && checkSlope < 0) cout << "/";
	else if(checkSlope == 0) cout << "|";
	else cout << "-";
}

int main() {
	int Px; // x of point
	int a, b, c, d, e;
	cout <<"請輸入5個係數: "; // 25 4 0 0 0 
	cin >> a >> b >> c >> d >> e;
	
	int lowerBound, upperBound;
	cout <<"請輸入x軸範圍: "; // 20 40
	cin >> lowerBound >> upperBound;
	
	cout <<"請輸入所求切點的x值: ";
	cin >> Px; // 30
	
	/* tangent line equation */
	double slope = pi/30 * (c*d*cos(d*pi/30*Px) - a*b*sin(b*pi/30*Px));
	printf("實際切線斜率:%lf\n", slope);
	/* Correction error */
	if(slope < 0.000000001 && slope > -0.000000001) slope = 0.0;
	
	/* print Y axis scale and decide wheather the start point is in the axis scale */
	cout <<"   -35  -30  -25  -20  -15  -10  -5    0    5    10   15   20   25   30   35"<< endl;
	double y = a * cos(b*pi/30*lowerBound) + c*sin(d*pi/30*lowerBound) + e;
	if(int(y) == 0)
		printf("----+----+----+----+----+----+----+--- %d---+----+----+----+----+----+----+----Y\n", lowerBound);
	else{
		// use for loop draw a Y-axis scale line
		for(int count = -39; count <= 40; count++){
			if(count == 40) printf("Y\n");
			else if(count == 0) printf("%d", lowerBound);
			else if(count == -1) printf(" ");
			else if(count == 1) continue;
			else if(count == int(y)) printf("*");
			else if(count % 5 == 0) printf("+");
			else printf("-");
		}
	}
	
	double Py = a * cos(b*pi/30*Px) + c*sin(d*pi/30*Px) + e;
	int lineLowerBound = Px - 5, lineUpperBound = Px + 5;
	for(int x=lowerBound+1; x<=upperBound; x++){
		y = a * cos(b*pi/30*x) + c*sin(d*pi/30*x) + e; // equation
		int tangent_line_y = slope * (x - Px) + Py; // tangent equation
		if(x != Px){
			if(lineLowerBound <= x && x <= lineUpperBound){
				for(int count = -39; count <= 40; count++){
					if(count == tangent_line_y && count == int(y)) printf("*");
					else if(count == tangent_line_y && x % 5 != 0) print_line((int)slope);
					else if(count == tangent_line_y && x % 5 == 0) print_line((int)slope);
					else if(count == 0 && x % 5 == 0){
						printf("%d", x);
						count++;
					}
					else if(count == 0) printf("|");
					else if(count == int(y)) printf("*");
					else printf(" ");
				}
			}
			else{
				for(int count = -39; count <= 40; count++){
					if(count == 0 && x % 5 == 0){
						printf("%d", x);
						count++;
					}
					else if(count == 0) printf("|");
					else if(count == int(y)) printf("*");
					else printf(" ");
				}
			}
		}
		else{
			for(int count = -39; count <= 40; count++){
				if(count == 0 && x % 5 == 0){
					printf("%d", x);
					count++;
				}
				else if(count == 0) printf("|");
				else if(count == int(y)-11) printf("( %d, %d ) P", Px, (int)y);
				else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
