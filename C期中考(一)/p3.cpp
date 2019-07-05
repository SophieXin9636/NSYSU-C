#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a[5];
	cout << "Enter five integers:";
	for(int i=0; i<5; i++){
		cin >> a[i];
	}
	sort(a, a+5);
	
	cout << endl;
	cout << "Largest is " << a[4] << endl;
	cout << "Second largest is " << a[3] << endl;
	return 0;
} 
