#include <iostream>
#include <string>

using namespace std;

// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------

class Subscriber{
public:
	Subscriber():name(""),numChannels(0){
		//cout <<"Name: " << name << endl;
		//cout <<"Number of Channels: "<< numChannels << endl << endl;
	}
	
	// mutator
	void setName(string inputName){
		name = inputName;
	}

	void setNumChannels(int num){
		numChannels = num;
	}

	// accessor
	string getName(){ return name; }
	int getNumChannels(){ return numChannels; }

	void InputData(){
		cout <<"Enter Subscriber name: " << endl;
		getline(cin, name);
		cout <<"Enter number of Channels: " << endl;
		cin >> numChannels;
		channelList = new string[numChannels];
		for(int i=0; i<numChannels; i++){
			//channelList[i] = new string;
			cout <<"Enter name of channel "<< i+1 <<": " << endl;
			cin >> channelList[i];
		}
		cout << endl;
	}

	void OutputData(){
		cout <<"Name: " << name << endl;
		cout <<"Number of Channels: " << numChannels << endl;
		for(int i=0; i<numChannels; i++){
			cout <<"Channel "<< i+1 <<": " << channelList[i] << endl;
		}
		cout << endl;
	}

	void ResetChannels(){
		//cout <<"Name: " << name << endl;
		setNumChannels(0);
		//cout <<"Number of Channels: " << numChannels << endl;
		//cout << endl;
	}


private:
	string name;
	int numChannels;
	string *channelList;
};




// --------------------------------
// --------- END USER CODE --------
// --------------------------------



// ============================================================
//     main function -- You are not allowed to change here!
// ============================================================
int main()
{
  // Test our code with two Subscriber classes
  Subscriber s1, s2;
  //Test of default constructor
  cout << "Test of default constructor:" << endl;
  s1.OutputData();

  s1.InputData();		// Input data for Subscriber 1
  cout << "Subscriber 1's data:" << endl;
  s1.OutputData();		// Output data for Subscriber 1

  cout << endl;

  s2 = s1;
  cout << "Subscriber 2's data after assignment from Subscriber 1:" << endl;
  s2.OutputData();		// Should output same data as for Subscriber 1

  s1.ResetChannels();
  cout << "Subscriber 1's data after reset:" << endl;
  s1.OutputData();		// Should have no channels

  cout << "Subscriber 2's data, should still have original channels:" << endl;
  s2.OutputData();		// Should still have original channels

  cout << endl;
  return 0;
}
