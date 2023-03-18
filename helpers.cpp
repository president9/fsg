#include <bits/stdc++.h>
#include "classes.h"
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

void gameLoop(Player &example){
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
            case -3:
                cout << "castle position out of bounds" << newl;
                break;
            case 1:
                break;
            default:
                cout << "unknown input" << newl;
                return;
        }
    }
}

void checkWinner(vector<int> &p1, vector<int> &p2){
    int p1Score = 0;
    int p2Score = 0;
    for(int i = 0; i < 10; i++){
        if(p1[i] > p2[i]){
            p1Score += p1[i] - p2[i];
        }
        if(p1[i] < p2[i]){
            p1Score += p2[i] - p1[i];
        }
    }
    if (p1Score > p2Score){
        cout << "P1 WINS" << newl;
    }
    else if (p1Score < p2Score){
        cout << "P2 WINS" << newl;
    }
    else {
        cout << "DRAW" << newl;
    }
}
