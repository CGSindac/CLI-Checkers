/*-- Libraries --*/
#include <iostream>
#include <string>
#include <sstream>

#include <vector>
#include <set>

#include <cctype>

#pragma once

/*-- CONSTANT VARIABLES --*/
#define BLACK 'B'
#define WHITE 'W'

#define XMAX 8
#define YMAX 8

struct piecePosition
{
    int xPosition;
    int yPosition;
};

bool inBounds (const piecePosition &position, int xShift, int yShift, int xMax, int yMAx);

piecePosition getInitPosition(const std::string);

std::set<std::string> getValidMoves(const char board[][9], piecePosition initialPos);

// void getValidTakes();

// void movePiece(const char board[][9], piecePosition initialPos);

void displayBoard(const char board[][9], int xMax, int yMax);
