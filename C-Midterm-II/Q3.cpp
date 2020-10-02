#include <iostream>
#include <string>
#include <vector>
using namespace std;

// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------

class BoxOfProduce{
public:
	BoxOfProduce(){}

	// mutator
	void setfv(int index, string inputfv){
		fv[index] = inputfv;
	}

	// accessor
	string getfv(int index){ return fv[index]; }

	void addBundle(string s){
		fv.push_back(s);
	}

	string boxContents(){
		string s = "The box contains:  ";
		for(int i=0; i<fv.size(); i++){
			s = s + "(" + char(i+'1') + ")" + fv[i] +" ";
		}
		return s;
	}

	BoxOfProduce operator+(BoxOfProduce obj){
		BoxOfProduce newFV;
		for(int i=0; i<fv.size(); i++){
			newFV.fv.push_back(getfv(i));
		}
		for(int i=0; i<obj.fv.size(); i++){
			newFV.fv.push_back(obj.getfv(i));
		}
		return newFV;
	}

	//ostream &operator<<(ostream out, BoxOfProduce obj){
	//	out <<
	//}

private:
	vector<string> fv;
};



// --------------------------------
// --------- END USER CODE --------
// --------------------------------
// ============================================================
//     main function -- You are not allowed to change here!
// ============================================================
int main()
{
	BoxOfProduce b1;
	b1.addBundle("Tomato");
	b1.addBundle("Potato");

	BoxOfProduce b2;
	b2.addBundle("Apple");
	b2.addBundle("Pear");
	b2.addBundle("Kiwi");
	b2.addBundle("Durian");

	BoxOfProduce b3;
	b3 = b1 + b2;

	cout << "box-1 " <<b1.boxContents() << endl;
	cout << "box-2 " <<b2.boxContents() << endl;
	cout << "box-3 " <<b3.boxContents() << endl;

	return 0;
}
