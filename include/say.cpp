#include "say.h"

piecePosition getInitPosition(const std::string strNotation) // Swap places due to array being in [y][x]
{                                                            // Return a position in [x][y] fromat and 0-indexed
    int x_pos = (int)(strNotation[1]) - '0';
    int y_pos = (int)tolower(strNotation[0]) - 'a';

    return {x_pos - 1, y_pos}; // Decrement x_pos because arrays are 0-indexed
}

bool inBounds (const piecePosition &position, int xShift, int yShift, int xMax, int yMAx)
{
    int xPosComputed = position.xPosition + xShift, 
        yPosComputed = position.yPosition + yShift;

    if (xPosComputed < 0 || xPosComputed >= xMax) return false; // Check if the computed x position is within [0, xMax]
    if (yPosComputed < 0 || yPosComputed >= yMAx) return false; // same for y value [0, yMax]

    return true;
}

std::set<std::string> getValidMoves(const char board[][9], piecePosition initialPos)
{   
    std::set<std::string> validMoves;
    std::stringstream tempMove;
    char currentPiece = board[initialPos.xPosition][initialPos.yPosition];

    std::cout << "CURRENT PIECE: " <<currentPiece << '\n';
    std::cout << "TOP LEFT: " << board[initialPos.xPosition - 1][initialPos.yPosition - 1] << '\n';
    std::cout << "TOP RIGHT: " << board[initialPos.xPosition - 1][initialPos.yPosition + 1] << '\n';

     

    // Check piece type in initial position

    if ( currentPiece == WHITE )
    {   
       
        if (board[initialPos.xPosition - 1][initialPos.yPosition + 1] != BLACK && inBounds(initialPos, -1, +1, XMAX, YMAX))  // check top right diagonal is free to move
        {   
            std::cout << "\nFLAG 1";
            tempMove.str(""); // Make sure SS is empty to format new moves
            tempMove.clear();

            tempMove << 'm' << (char)('a' + (initialPos.yPosition + 1)) << (char)((initialPos.xPosition - 1 + 1) + '0');

            validMoves.insert(tempMove.str());
        } 
        
        if (board[initialPos.xPosition - 1][initialPos.yPosition - 1] != BLACK && inBounds(initialPos, -1, -1, XMAX, YMAX)) // check top left diagonal
        {
            std::cout << "\nFLAG 2\n";

            tempMove.str(""); // Make sure SS is empty to format new moves
            tempMove.clear();

            tempMove << 'm' << (char)('a' + (initialPos.yPosition - 1)) << (char)((initialPos.xPosition - 1 + 1) + '0');

            validMoves.insert(tempMove.str());
        }
        
    }

    return validMoves;
}

void displayBoard(const char board[][9], int xMax, int yMax)
{
   for (int i = 0; i < yMax ; i++ )
   {
       std::cout << i + 1 << " | "; // Print Y indicators
       for (char c : board[i])
       {
           std::cout << c << " ";
       }
       std::cout << '\n';
   }
   std::cout << "& | ";
   
   // Print X indicators
   for (int i = 0 ; i < xMax ; i++)
   {
    std::cout << (char)('a' + i) << ' ';
   }

   std::cout << '\n';
}