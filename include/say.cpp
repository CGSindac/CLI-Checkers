#include "say.h"

piecePosition getPosition(const std::string strNotation) // Swap places due to array being in [y][x]
{   
    int y_pos = (int)(strNotation[1]) - '0',
        x_pos = (int)tolower(strNotation[0]) - 'a';
                                                                  
    return {x_pos, y_pos - 1}; // Decrement x_pos because arrays are 0-indexed
}

piecePosition getPositionFromAction(const std::string action)
{
     int y_pos = (int)(action[2]) - '0',
         x_pos = (int)tolower(action[1]) - 'a';
                                                                  
    return {x_pos, y_pos - 1}; // Decrement x_pos because arrays are 0-indexed
}

bool inBounds (const piecePosition &position, int xShift, int yShift, int xMax, int yMAx)
{
    int xPosComputed = position.xPosition + xShift, 
        yPosComputed = position.yPosition + yShift;

    if (xPosComputed < 0 || xPosComputed >= xMax) return false; // Check if the computed x position is within [0, xMax]
    if (yPosComputed < 0 || yPosComputed >= yMAx) return false; // same for y value [0, yMax]

    return true;
}
void getValidTakes(std::set<std::string> &moveList, char piece, const char board[][9], int xPos, int yPos, std::string prevTake = "")
{   
    // std::cout <<"\nPiece: " << piece << "\n";
    piecePosition currPosition {xPos, yPos};
    std::stringstream temp;

    if (piece == WHITE)
    {   
        // Top Right Daigonal
        if  (   board[yPos - 1][xPos + 1] == BLACK && board[yPos - 2][xPos + 2] != BLACK
                && inBounds(currPosition, +1, -1, XMAX, YMAX)
                && inBounds(currPosition, +2, -2, XMAX, YMAX)
            )
        {
            temp.str("");
            temp.clear();

            temp << prevTake << 'x' << (char)('a' + (xPos + 2)) << (char)((yPos - 2 + 1) + '0');

            std::string move = temp.str();

            moveList.insert(move);

            getValidTakes(moveList,piece,board,xPos + 2, yPos - 2, move);
        }

        // Top Left Diagonal
        if  (   board[yPos - 1][xPos - 1] == BLACK && board[yPos - 2][xPos - 2] != BLACK
                && inBounds(currPosition, -1, -1, XMAX, YMAX)
                && inBounds(currPosition, -2, -2, XMAX, YMAX)
            )
        {
            temp.str("");
            temp.clear();

            temp << prevTake << 'x' << (char)('a' + (xPos - 2)) << (char)((yPos - 2 + 1) + '0');

            std::string move = temp.str();

            moveList.insert(move);

            getValidTakes(moveList,piece,board,xPos - 2, yPos - 2, move);
        }
        
    }else if (piece == BLACK)
    {
        // Top Right Daigonal
        if  (   board[yPos + 1][xPos + 1] == WHITE && board[yPos + 2][xPos + 2] != WHITE
                && inBounds(currPosition, +1, +1, XMAX, YMAX)
                && inBounds(currPosition, +2, +2, XMAX, YMAX)
            )
        {
            // std::cout << "\nFlag 3-1\n";
            temp.str("");
            temp.clear();

            temp << prevTake << 'x' << (char)('a' + (xPos + 2)) << (char)((yPos + 2 + 1) + '0');

            std::string move = temp.str();

            moveList.insert(move);

            getValidTakes(moveList,piece,board,xPos + 2, yPos + 2, move);
        }

        // Top Left Diagonal
        if  (   board[yPos + 1][xPos - 1] == WHITE && board[yPos + 2][xPos - 2] != WHITE
                && inBounds(currPosition, -1, +1, XMAX, YMAX)
                && inBounds(currPosition, -2, +2, XMAX, YMAX)
            )
        {   
            // std::cout << "\nFlag 3-2\n";

            temp.str("");
            temp.clear();

            temp << prevTake << 'x' << (char)('a' + (xPos - 2)) << (char)((yPos + 2 + 1) + '0');

            std::string move = temp.str();

            moveList.insert(move);

            getValidTakes(moveList,piece,board,xPos - 2, yPos + 2, move);
        }
    }

    return;
    
}


std::set<std::string> getValidMoves(const char board[][9], piecePosition initialPos)
{   
    std::set<std::string> validMoves;
    std::stringstream tempMove;
    char currentPiece = board[initialPos.yPosition][initialPos.xPosition];

    // std::cout << "CURRENT PIECE: " <<currentPiece << '\n';
    
    // Check piece type in initial position

    if ( currentPiece == WHITE )
    {   
        std::cout << "TOP LEFT: " << board[initialPos.yPosition - 1][initialPos.xPosition - 1] << '\n';
        std::cout << "TOP RIGHT: " << board[initialPos.yPosition - 1][initialPos.xPosition + 1] << '\n';
       
        if (board[initialPos.yPosition - 1][initialPos.xPosition + 1] != BLACK && board[initialPos.yPosition - 1][initialPos.xPosition + 1] != WHITE && inBounds(initialPos, +1, -1, XMAX, YMAX))  // check top right diagonal is free to move
        {   
             //std::cout << "\nFLAG 1";

            tempMove.str(""); // Make sure SS is empty to format new moves
            tempMove.clear();

            tempMove << 'm' << (char)('a' + (initialPos.xPosition + 1)) << (char)((initialPos.yPosition - 1 + 1) + '0');

            validMoves.insert(tempMove.str());
        }     

        if (board[initialPos.yPosition - 1][initialPos.xPosition - 1] != BLACK && board[initialPos.yPosition - 1][initialPos.xPosition - 1] != WHITE && inBounds(initialPos, -1, -1, XMAX, YMAX)) // check top left diagonal
        {
             //std::cout << "\nFLAG 2\n";

            tempMove.str(""); // Make sure SS is empty to format new moves
            tempMove.clear();

            tempMove << 'm' << (char)('a' + (initialPos.xPosition - 1)) << (char)((initialPos.yPosition - 1 + 1) + '0');

            validMoves.insert(tempMove.str());
        }      
    } else if ( currentPiece == BLACK)
    {
        //std::cout << "BOTTOM LEFT: " << board[initialPos.yPosition + 1][initialPos.xPosition - 1] << '\n';
        //std::cout << "BOTTOM RIGHT: " << board[initialPos.yPosition + 1][initialPos.xPosition + 1] << '\n';
        if (board[initialPos.yPosition + 1][initialPos.xPosition + 1] != WHITE && board[initialPos.yPosition + 1][initialPos.xPosition + 1] != BLACK && inBounds(initialPos, +1, +1, XMAX, YMAX))  // check top right diagonal is free to move
        {   
             //std::cout << "\nFLAG 1\n";

            tempMove.str(""); // Make sure SS is empty to format new moves
            tempMove.clear();

            tempMove << 'm' << (char)('a' + (initialPos.xPosition + 1)) << (char)((initialPos.yPosition + 1 + 1) + '0');

            validMoves.insert(tempMove.str());
        } 
        
        if (board[initialPos.yPosition + 1][initialPos.xPosition - 1] != WHITE && board[initialPos.yPosition + 1][initialPos.xPosition - 1] != BLACK && inBounds(initialPos, -1, +1, XMAX, YMAX)) // check top left diagonal
        {
             //std::cout << "\nFLAG 2\n";

            tempMove.str(""); // Make sure SS is empty to format new moves
            tempMove.clear();

            tempMove << 'm' << (char)('a' + (initialPos.xPosition - 1)) << (char)((initialPos.yPosition + 1 + 1) + '0');

            validMoves.insert(tempMove.str());
        }
    }

    getValidTakes(validMoves, currentPiece, board, initialPos.xPosition, initialPos.yPosition);


    return validMoves;
}
void movePiece(char board[][9], piecePosition initialPos, std::string action)
{
    // Get Final Position
    piecePosition finalPos = getPositionFromAction(action);
    
    // Swap with new position    
    std::swap(board[initialPos.yPosition][initialPos.xPosition], board[finalPos.yPosition][finalPos.xPosition]);

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