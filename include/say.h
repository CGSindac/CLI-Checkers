#include <iostream>
#include <string>
#include <cctype>
#pragma once

// Boards


struct piecePosition
{
    int xPosition;
    int yPosition;
};


void testing();
piecePosition getInitPosition(const std::string);
void displayBoard(std::string board[]);
