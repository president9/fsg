#include <bits/stdc++.h>
#include "./helpers.cpp"

#define newl "\n"
using namespace std;

int main(int argc, char** argv){
    showInstructions();
    int player = 1;
    string p1 = nextPlayerPrompt(player++);
    Player player1(p1);
    gameLoop(player1);
    string p2 = nextPlayerPrompt(player++);
    Player player2(p2);
    gameLoop(player2);
    return EXIT_SUCCESS;
}

