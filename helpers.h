#pragma once
#include "classes.h"

void showInstructions();
string nextPlayerPrompt(int i);
void gameLoop(Player& example);
void checkWinner(vector<int> &p1, vector<int> &p2);

