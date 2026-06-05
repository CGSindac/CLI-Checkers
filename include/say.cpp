#include "say.h"


void testing()
{
    piecePosition sample{2, 3};

    std::cout << sample.xPosition << ' ' << sample.yPosition;
}

piecePosition getInitPosition(const std::string strNotation)
{
    int x_pos = (int)(strNotation[1]) - '0';
    int y_pos = (int)tolower(strNotation[0]) - 'a';

    return {x_pos - 1, y_pos}; // Decrement x_pos because arrays are 0-indexed
}

void displayBoard(std::string board[])
{
    for (std::string row : board)
    {
        for (char column : row)
        {
            std:: cout << row << ' ';
        }
    }
}