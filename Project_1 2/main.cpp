//File: main.cpp
#include <iostream>
#include "code.h"
#include "response.h"
#include "mastermind.h"
//#include <vector>

using namespace std;

int main()
{
    mastermind game; //creates an object named 'game' of class 'mastermind'
    game.playGame(); //initializes random code
};