#include <string>
#include <iostream>
using namespace std;

// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------

class DynamicStringArray{
public:
	DynamicStringArray():dynamicArray(NULL),size(0){}

	DynamicStringArray(const DynamicStringArray &obj){
		dynamicArray = obj.dynamicArray;
		size = obj.size;
	}
	int getSize(){ return size; }

	void addEntry(string input){
	
		if(size == 0) dynamicArray = new string[100];
		dynamicArray[size] = input;
		size += 1;
	}

	void deleteEntry(string input){
		for(int i=0; i<size; i++){
			if(dynamicArray[i] == input){
				dynamicArray[i] = "";
				delete &(dynamicArray+i);
			}
		}
	}

	string getEntry(int index){
		string input = dynamicArray[index];
		return input;
	}

	~DynamicStringArray(){
		delete dynamicArray;
	}

private:
	string *dynamicArray;
	int size;
};


// --------------------------------
// --------- END USER CODE --------
// --------------------------------

// ============================================================
//     main function -- You are not allowed to change here!
// ============================================================
int main()
{
	DynamicStringArray names;

	// List of names
	names.addEntry("Allen");
	names.addEntry("Bob");
	names.addEntry("Ciro");
	names.addEntry("David");
	names.addEntry("Eddie");

	// Output list
	cout << "List of names:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  // Add and remove some names
  names.addEntry("Frank");
  cout << "After adding a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  names.deleteEntry("Bob");
  cout << "After removing a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  names.deleteEntry("Garfield");
  cout << "After removing a name that isn't on the list (Garfield):" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  names.addEntry("Hamlet");
  cout << "After adding another name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  // Remove all of the names by repeatedly deleting the last one
  while (names.getSize() > 0) {
        names.deleteEntry(names.getEntry(names.getSize() - 1));
  }

  cout << "After removing all of the names:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  names.addEntry("Isaac");
  cout << "After adding a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

	cout << "Testing copy constructor" << endl;
	DynamicStringArray names2(names);
	// Remove Isaac from names
	names.deleteEntry("Isaac");
  	cout << "Copied names:" << endl;
	for (int i = 0; i < names2.getSize(); i++)
		cout << names2.getEntry(i) << endl;
	cout << endl;

	cout << "Testing assignment" << endl;
	DynamicStringArray names3 = names2;
	// Remove Isaac from names2
	names2.deleteEntry("Isaac");
     	cout << "Copied names:" << endl;
	for (int i = 0; i < names3.getSize(); i++)
		cout << names3.getEntry(i) << endl;
	cout << endl;

	cout << "Enter a character to exit." << endl;
	char wait;
	cin >> wait;
	return 0;
}
