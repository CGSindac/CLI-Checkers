#include "say.h"

piecePosition getPosition(const std::string strNotation) // Swap places due to array being in [y][x]
{   
    int y_pos = (int)(strNotation[1]) - '0',
        x_pos = (int)tolower(strNotation[0]) - 'a';
                                                                  
    return {x_pos, y_pos - 1}; // Decrement x_pos because arrays are 0-indexed
}

piecePosition getPositionFromAction(const std::string action) 
{
    /*
     *
     * Sample action string notation ma4 / xf3
     *                  [type of move] [X-index] [Y-index]
     * 
     */

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
std::string formatPosition(char prefix, int  x, int y)
{
    std::stringstream temp;
    temp << prefix << (char)('a' + x) << std::to_string(y+1);

    return temp.str();
}

int countPieces(const char board[][9], char side, int xMax, int yMax)
{
    int count = 0;
    
    if (side == WHITE)
    {
        for (int i = 0; i < yMax ; i++ )
        {
            for (char c : board[i])
            {
                if (c == WHITE) ++count;
            }
        }
    }else
    {
        for (int i = 0; i < yMax ; i++ )
        {
            for (char c : board[i])
            {
                if (c == BLACK) ++count;
            }
        }
    }

    return count;
}

void getValidTakes(std::set<std::string> &moveList, char piece, const char board[][9], int xPos, int yPos, std::string prevTake = "")
{   
    // std::cout <<"\nPiece: " << piece << "\n";
    piecePosition currPosition {xPos, yPos};
    std::stringstream temp;

    if (piece == WHITE || piece == QWHITE)
    {   
        // Top Right Daigonal
        if  (   board[yPos - 1][xPos + 1] == BLACK && board[yPos - 2][xPos + 2] == '#'
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
        if  (   board[yPos - 1][xPos - 1] == BLACK && board[yPos - 2][xPos - 2] == '#'
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

        // Bottom Right
        if  (   board[yPos + 1][xPos + 1] == BLACK && board[yPos + 2][xPos + 2] == '#'
                && inBounds(currPosition, +1, +1, XMAX, YMAX)
                && inBounds(currPosition, +2, +2, XMAX, YMAX)
                && piece == QWHITE
            )
        {
            temp.str("");
            temp.clear();

            temp << prevTake << 'x' << (char)('a' + (xPos - 2)) << (char)((yPos - 2 + 1) + '0');

            std::string move = temp.str();

            moveList.insert(move);

            getValidTakes(moveList,piece,board,xPos + 2, yPos + 2, move);
        }
        // Bottom left
        if  (   board[yPos + 1][xPos - 1] == BLACK && board[yPos + 2][xPos - 2] == '#'
                && inBounds(currPosition, -1, +1, XMAX, YMAX)
                && inBounds(currPosition, -2, +2, XMAX, YMAX)
                && piece == QWHITE
            )
        {
            temp.str("");
            temp.clear();

            temp << prevTake << 'x' << (char)('a' + (xPos - 2)) << (char)((yPos - 2 + 1) + '0');

            std::string move = temp.str();

            moveList.insert(move);

            getValidTakes(moveList,piece,board,xPos - 2, yPos + 2, move);
        }
        
    }else if (piece == BLACK || piece == QBLACK)
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

void getValidQueenTakes(std::set<std::string> &moveList, std::vector<std::string> visited, char piece, char board[][9], int xPos, int yPos, std::string prevTake = "")
{
    /*
    *
    * Apply Breadth first Search
    * 
    */

    std::string currPos = formatPosition('#', xPos, yPos);
    piecePosition currPosCord = {xPos, yPos};

    char copyBoard[8][9];
    memcpy(copyBoard, board, 72);

    // Check id tile is already visited
    auto it = std::find(visited.begin(), visited.end(), currPos);

    if (it != visited.end() && currPos != visited[0]) return;

    // Add current tile to visited tiles
    visited.push_back(currPos);
    // std::cout << "VISITED[0] : " << visited[0] << std::endl;
    // std::cout << "CURRENT POS: " << currPos << std::endl;

    char opposingPiece  =   (piece == 'Q' ? 'B' : 'W'),
         opposingQPiece =   (piece == 'Q' ? 'q' : 'Q');

    // Check Diagonals

    // Top Right

    if (
        (copyBoard[yPos - 1][xPos + 1] == opposingPiece || copyBoard[yPos - 1][xPos + 1] == opposingQPiece) &&
        (copyBoard[yPos - 2][xPos + 2] == '#')
       )
    {
        std::string move = prevTake + formatPosition('x', xPos + 2, yPos - 2);
        moveList.insert(move);

        char localBoard[8][9];
        memcpy(localBoard, copyBoard, 72);

        localBoard[yPos - 1][xPos + 1] = '#';
        std::swap(localBoard[yPos][xPos], localBoard[yPos-2][xPos+2]);

        getValidQueenTakes(moveList, visited, piece, localBoard, xPos + 2, yPos - 2, move);
    }
    
    // Top Left
    if (
        (copyBoard[yPos - 1][xPos - 1] == opposingPiece || copyBoard[yPos - 1][xPos - 1] == opposingQPiece) &&
        (copyBoard[yPos - 2][xPos - 2] == '#')
       )
    {
        std::string move = prevTake + formatPosition('x', xPos - 2, yPos - 2);
        moveList.insert(move);

        char localBoard[8][9];
        memcpy(localBoard, copyBoard, 72);

        localBoard[yPos - 1][xPos - 1] = '#';
        std::swap(localBoard[yPos][xPos], localBoard[yPos-2][xPos-2]);

        getValidQueenTakes(moveList, visited, piece, localBoard, xPos - 2, yPos - 2, move);
    }

    // Bottom Right
    if (
        (copyBoard[yPos + 1][xPos + 1] == opposingPiece || copyBoard[yPos + 1][xPos + 1] == opposingQPiece) &&
        (copyBoard[yPos + 2][xPos + 2] == '#')
       )
    {
        std::string move = prevTake + formatPosition('x', xPos + 2, yPos + 2);
        moveList.insert(move);

        char localBoard[8][9];
        memcpy(localBoard, copyBoard, 72);

        localBoard[yPos + 1][xPos + 1] = '#';
        std::swap(localBoard[yPos][xPos], localBoard[yPos+2][xPos+2]);

        getValidQueenTakes(moveList, visited, piece, localBoard, xPos + 2, yPos + 2, move);
    }
    // Bottom Left
    if (
        (copyBoard[yPos + 1][xPos - 1] == opposingPiece || copyBoard[yPos + 1][xPos - 1] == opposingQPiece) &&
        (copyBoard[yPos + 2][xPos - 2] == '#')
       )
    {
        std::string move = prevTake + formatPosition('x', xPos - 2, yPos + 2);
        moveList.insert(move);

        char localBoard[8][9];
        memcpy(localBoard, copyBoard, 72);

        localBoard[yPos + 1][xPos - 1] = '#';
        std::swap(localBoard[yPos][xPos], localBoard[yPos+2][xPos-2]);

        getValidQueenTakes(moveList, visited, piece, localBoard, xPos - 2, yPos + 2, move);
    }
}

std::set<std::string> getValidMoves(const char board[][9], piecePosition initialPos)
{   
    std::set<std::string> validMoves;
    std::stringstream tempMove;
    char currentPiece = board[initialPos.yPosition][initialPos.xPosition];

    
    // Check piece type in initial position

    if ( currentPiece == WHITE || currentPiece == QWHITE || currentPiece == QBLACK )
    {   
       
        if (board[initialPos.yPosition - 1][initialPos.xPosition + 1] != BLACK && 
            board[initialPos.yPosition - 1][initialPos.xPosition + 1] != WHITE && 
            board[initialPos.yPosition - 1][initialPos.xPosition + 1] != QBLACK && 
            board[initialPos.yPosition - 1][initialPos.xPosition + 1] != QWHITE && inBounds(initialPos, +1, -1, XMAX, YMAX))  // check top right diagonal is free to move
        {   
             //std::cout << "\nFLAG 1";

            tempMove.str(""); // Make sure SS is empty to format new moves
            tempMove.clear();

            tempMove << 'm' << (char)('a' + (initialPos.xPosition + 1)) << (char)((initialPos.yPosition - 1 + 1) + '0');

            validMoves.insert(tempMove.str());
        }     

        if (board[initialPos.yPosition - 1][initialPos.xPosition - 1] != BLACK && 
            board[initialPos.yPosition - 1][initialPos.xPosition - 1] != WHITE && 
            board[initialPos.yPosition - 1][initialPos.xPosition - 1] != QBLACK && 
            board[initialPos.yPosition - 1][initialPos.xPosition - 1] != QWHITE && inBounds(initialPos, -1, -1, XMAX, YMAX)) // check top left diagonal
        {
             //std::cout << "\nFLAG 2\n";

            tempMove.str(""); // Make sure SS is empty to format new moves
            tempMove.clear();

            tempMove << 'm' << (char)('a' + (initialPos.xPosition - 1)) << (char)((initialPos.yPosition - 1 + 1) + '0');

            validMoves.insert(tempMove.str());
        }      
    } 
    
    if ( currentPiece == BLACK || currentPiece == QWHITE || currentPiece == QBLACK )
    {
        //std::cout << "BOTTOM LEFT: " << board[initialPos.yPosition + 1][initialPos.xPosition - 1] << '\n';
        //std::cout << "BOTTOM RIGHT: " << board[initialPos.yPosition + 1][initialPos.xPosition + 1] << '\n';
        if (board[initialPos.yPosition + 1][initialPos.xPosition + 1] != WHITE && 
            board[initialPos.yPosition + 1][initialPos.xPosition + 1] != BLACK && 
            board[initialPos.yPosition + 1][initialPos.xPosition + 1] != QWHITE && 
            board[initialPos.yPosition + 1][initialPos.xPosition + 1] != QBLACK && inBounds(initialPos, +1, +1, XMAX, YMAX))  // check top right diagonal is free to move
        {   
             //std::cout << "\nFLAG 1\n";

            tempMove.str(""); // Make sure SS is empty to format new moves
            tempMove.clear();

            tempMove << 'm' << (char)('a' + (initialPos.xPosition + 1)) << (char)((initialPos.yPosition + 1 + 1) + '0');

            validMoves.insert(tempMove.str());
        } 
        
        if (board[initialPos.yPosition + 1][initialPos.xPosition - 1] != WHITE && 
            board[initialPos.yPosition + 1][initialPos.xPosition - 1] != BLACK && 
            board[initialPos.yPosition + 1][initialPos.xPosition - 1] != WHITE && 
            board[initialPos.yPosition + 1][initialPos.xPosition - 1] != BLACK && inBounds(initialPos, -1, +1, XMAX, YMAX)) // check top left diagonal
        {
             //std::cout << "\nFLAG 2\n";

            tempMove.str(""); // Make sure SS is empty to format new moves
            tempMove.clear();

            tempMove << 'm' << (char)('a' + (initialPos.xPosition - 1)) << (char)((initialPos.yPosition + 1 + 1) + '0');

            validMoves.insert(tempMove.str());
        }
    }

    if (currentPiece == QWHITE || currentPiece == QBLACK)
    {
        std::vector<std::string> visited;
        char copyBoard[8][9];
        memcpy(copyBoard, board, 72);

        getValidQueenTakes(validMoves, visited, currentPiece, copyBoard, initialPos.xPosition, initialPos.yPosition);
    }
    else
        getValidTakes(validMoves, currentPiece, board, initialPos.xPosition, initialPos.yPosition);
    

    return validMoves;
}

void updateBoardPieces (char board[][9])
{
    for (int column = 0; column < XMAX; ++column)
    {
        if (board[0][column] == WHITE)
        {
            board[0][column] = QWHITE;
        }

        if (board[YMAX-1][column] == BLACK)
        {
            board[YMAX-1][column] = QBLACK;
        }
    }
}

void movePiece(char board[][9], piecePosition initialPos, std::string action)
{
    // Get Final Position
    piecePosition finalPos = getPositionFromAction(action);
    
    // Swap with new position    
    std::swap(board[initialPos.yPosition][initialPos.xPosition], board[finalPos.yPosition][finalPos.xPosition]);

}

void takeAction(char board[][9], piecePosition initialPos, std::string action)
{
    if ((int)action[0] == 0) return; // Magic shit, checking if action is '\0' the ending of any string or simply checks if action is empty string;

    std::string nextAction = action.substr(3); // 3rd index guaranteed to either be 'x' or '\0'

    piecePosition finalPos = getPositionFromAction(action);

    int xPosBetween = (initialPos.xPosition + finalPos.xPosition) / 2, 
        yPosBetween = (initialPos.yPosition + finalPos.yPosition) / 2;
    
    board[yPosBetween][xPosBetween] = board[finalPos.yPosition][finalPos.xPosition];
    std::swap(board[initialPos.yPosition][initialPos.xPosition], board[finalPos.yPosition][finalPos.xPosition]);

    takeAction(board, finalPos, nextAction);
}
void displayBoard(const char board[][9], int xMax, int yMax)
{
    std::cout << "\n";
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