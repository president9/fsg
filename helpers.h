#pragma once
#include "classes.h"

void showInstructions();
void winnerMessage();
string nextPlayerPrompt(int i);
void gameLoop(Player& example);
void checkWinner(vector<int> &p1, vector<int> &p2);

