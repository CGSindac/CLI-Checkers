#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#pragma once

struct piecePosition
{
    int xPosition;
    int yPosition;
};


piecePosition getInitPosition(const std::string);


void displayBoard(const char board[][9], int xMax, int yMax);
