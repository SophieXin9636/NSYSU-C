#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Please complete the program here by class definition
                                  and function definitions*/
// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------

class Player{
  public:
	Player(){}
	Player(string n, int s):name(n),score(s){}
	string getName(){ return name; }
	int getScore(){ return score; }
	friend void addPlayer(int &numPlayers, vector<Player> &players);
	friend void printPlayer(int &numPlayers, vector<Player> &players);
	friend void searchPlayer(int &numPlayers, vector<Player> &players);
	friend void removePlayer(int &numPlayers, vector<Player> &players);
	friend void swap(Player &a, Player &b);
	Player operator=(Player obj){
		name = obj.name;
		score = obj.score;
		return *this;
	}

  private:
	string name;
	int score;
};

void addPlayer(int &numPlayers, vector<Player> &players){
	if(numPlayers >= 5){
	   cout <<"Player array full.\n";
	   return;
	}
	string str;
	int grade;
	cout <<"Enter new player name: "<< endl; 
	cin >> str;
	cout <<"Enter new player score: "<< endl;
	cin >> grade;

	Player newplayer(str, grade);
	players.push_back(newplayer);
	numPlayers += 1;
}

void printPlayer(int &numPlayers, vector<Player> &players){
	cout <<"Player Scores: " << endl;
	for(int i=0; i<numPlayers; i++){
	    cout << players[i].name <<" " << players[i].score << endl;
	}
}

void searchPlayer(int &numPlayers, vector<Player> &players){
	string strname;
	cout <<"What player to search for?" << endl; 
	cin >> strname;
	for(int i=0; i<numPlayers; i++){
	    if(players[i].name == strname){
	    	cout <<"The score for " << players[i].name <<" is " << players[i].score << endl;
		return;
	    }
	}
	cout <<"Player " << strname <<" not found.\n";
}

void removePlayer(int &numPlayers, vector<Player> &players){
	if(numPlayers == 0){
	    cout <<"There is no player in this array.\n";
	}
	string n;
	cout <<"What player to remove?" << endl; 
	cin >> n;
	for(int i=0; i<numPlayers; i++){
	    if(players[i].name == n){
		if(i != numPlayers-1){
			swap(players[i], players[numPlayers]);
		}
	    	players.pop_back();
		cout <<"Player " << n << " removed.\n";
		return;
	    }
	}
	cout <<"Player " << n <<" not found.\n";
}

void swap(Player &a, Player &b){
	Player temp;
	temp.name = a.name;
	a.name = b.name;
	b.name = temp.name;

	temp.score = a.score;
	a.score = b.score;
	b.score = temp.score;

}
// --------------------------------
// --------- END USER CODE --------
// --------------------------------

// You cannot change this part of code
int main()
{
  char option;
  vector<Player> players;
  int numPlayers=0;

  do
  {
   cout << "Enter an option." << endl;
   cout << "a. Add new player and score." << endl;
   cout << "b. Print all players and scores." << endl;
   cout << "c. Search for a player's score." << endl;
   cout << "d. Remove a player." << endl;
   cout << "e. Quit." << endl;

   cin >> option;
   cout << endl;
   if (option == 'a')
     addPlayer(numPlayers, players);
   else if (option == 'b')
     printPlayer(numPlayers, players);
   else if (option == 'c')
     searchPlayer(numPlayers, players);
   else if (option == 'd')
     removePlayer(numPlayers, players);
   cout << endl;
  } while (option != 'e');

  return 0;
}
