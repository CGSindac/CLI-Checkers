/*-- Libraries --*/
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>

#include <vector>
#include <set>

#include <cctype>

#pragma once

/*-- CONSTANT VARIABLES --*/
#define QBLACK 'q'
#define BLACK  'B'
#define WHITE  'W'
#define QWHITE 'Q'

#define XMAX 8
#define YMAX 8

struct piecePosition
{
    int xPosition;
    int yPosition;
};

bool inBounds (const piecePosition &position, int xShift, int yShift, int xMax, int yMAx);

int countPieces(const char board[][9], char piece, int xMax, int yMax);

piecePosition getPosition(const std::string);

piecePosition getPositionFromAction(const std::string);

std::set<std::string> getValidMoves(const char board[][9], piecePosition initialPos);

std::string formatPosition(char, int , int);

void updateBoardPieces (char board[][9]); // Ugrades pieces to queens when they reach the bottom/top of the board

void getValidTakes(std::set<std::string> &moveList, char piece, const char board[][9], int xPos, int yPos, std::string prevTake);

void getValidQueenTakes(std::set<std::string> &moveList, std::vector<std::string> visited, char piece,  char board[][9], int xPos, int yPos, std::string prevTake);

void movePiece(char board[][9], piecePosition initialPos, std::string action);

void takeAction(char board[][9], piecePosition initialPos, std::string action);

void displayBoard(const char board[][9], int xMax, int yMax);

// TODO: QUEEN MOVEMENT
// 