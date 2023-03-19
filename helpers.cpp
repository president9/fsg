#include <iostream>
#include <vector>
#include <string>

#include "classes.h"
#define newl "\n"
using namespace std;


void showInstructions(){
    cout << "Player 1 has 10 castles (A) and 100 soldiers and so does player 2" << newl;
    cout << "Each player allocates some amount of soldiers in each castle " << newl;
    cout << "and a players scores (starts at 0) is increased by A[i] - B[i]" << newl;
    cout << "where A[i] and B[i] denote the number of soldiers in the ith castles" << newl;
    cout << "of player 1 and player 2 respectively. When calculating final points," << newl;
    cout << "each players' score is increased by 2*w where \'w\' is the player's " << newl;
    cout << "longest winstreak. The player with most points wins." << newl;
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
    // implement winstreak
    int p1Score = 0;
    int p2Score = 0;
    int p1Winstreak = 0;
    int p1LongestWinstreak = 0;
    int p2Winstreak = 0;
    int p2LongestWinstreak = 0;
    for(int i = 0; i < 10; i++){
        if(p1[i] > p2[i]){
            p1Score += p1[i] - p2[i];
            p1Winstreak++;
            p2Winstreak= 0;
        }
        if(p1[i] < p2[i]){
            p2Score += p2[i] - p1[i];
            p2Winstreak++; 
            p1Winstreak = 0;
        }
        p1LongestWinstreak = max(p1LongestWinstreak, p1Winstreak);
        p2LongestWinstreak = max(p2LongestWinstreak, p2Winstreak);
    }
    cout << "P1 has " << p1Score + 2*p1LongestWinstreak << " points." << newl;
    cout << "P2 has " << p2Score + 2*p2LongestWinstreak << " points." << newl;

    if (p1Score + 2*p1LongestWinstreak > p2Score + 2*p2LongestWinstreak){
        cout << "P1 WINS" << newl;
    }
    else if (p1Score + 2*p1LongestWinstreak < p2Score + 2*p2LongestWinstreak){
        cout << "P2 WINS" << newl;
    }
    else {
        cout << "DRAW" << newl;
    }
}
