#include <bits/stdc++.h>
#define newl "\n"
using namespace std;

// player will not print error messages.
class Player{
    private:
        string playerName;
        vector<int> castles;
        // vector<int> castle(10,0); 
        // you cannot initialize a member variable directly inside a class declaration.
    public:
        int numSoldiers = 100;
        Player(string name) : playerName(name), castles(vector<int>(5,0)){ // initialise what u want the variable to be
            // constructor body
            /*The "// constructor body" comment is a placeholder for any code that you want to execute in 
              the constructor after the member variables have been initialized.*/
            cout << "Player of name \"" << this->playerName << "\" created." << newl;
            // will print "Player of name ...." after the object has been made
        }
        void printCastles(){
            cout << "Current config: ";
            for(auto x: castles){
                cout << x << " ";
            }
            cout << newl;
        }
        // assign soldiers function
        int assignSoldiers(int soldiers, int castleID){
            if(soldiers > this->numSoldiers){
                return -1;
            }
            if(soldiers < 0){
                return -2;
            }
            if(soldiers < castles[castleID - 1]){
                numSoldiers += castles[castleID - 1];
            }
            else{
                this->numSoldiers -= soldiers - castles[castleID-1];
                this->castles[castleID - 1] = soldiers;
                return 1;
            }
            return -1;
        }
};

