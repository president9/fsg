#include <bits/stdc++.h>
#include "./classes.cpp"
#define newl "\n"
using namespace std;


void showInstructions(){
    cout << "This is a game of JSG. Play properly." << newl;
}

void winnerMessage(){
    cout << "player wins" << newl;
}

string nextPlayerPrompt(int i){
    string name;
    cout << "Player " << i << " enter name: " << newl;
    cin >> name;
    return name;
}

void gameLoop(Player& example){
    int soldiers, castle;
    while(example.numSoldiers > 0){
        example.printCastles();
        cout << "Remanining soldiers: " << example.numSoldiers << newl;
        cin >> soldiers;
        cin >> castle;
        switch(example.assignSoldiers(soldiers, castle)){
            case -1:
                cout << "too many soldiers" << newl;
                break;
            case -2:
                cout << "too few soldiers" << newl;
                break;
            case 1:
                break;
            default:
                cout << "unknown input" << newl;
        }
    }
}

