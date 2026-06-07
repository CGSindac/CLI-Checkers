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

piecePosition getPosition(const std::string);

piecePosition getPositionFromAction(const std::string);

std::set<std::string> getValidMoves(const char board[][9], piecePosition initialPos);

void getValidTakes(std::set<std::string> &moveList, char piece, const char board[][9], int xPos, int yPos, std::string prevTake);

void movePiece( char board[][9], piecePosition initialPos, std::string action);



void displayBoard(const char board[][9], int xMax, int yMax);
