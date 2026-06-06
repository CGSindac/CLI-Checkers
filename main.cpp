#include <iostream>
#include "include/say.h"

char boardMain[8][9] =
{

"B+B+B+B+",
"+#+#+B+B",
"B+B+B+B+",
"+#+B+#+#",
"#+B+B+#+",
"+W+W+W+W",
"W+W+W+W+",
"+W+W+W+W"

};

const char boardBase[8][9] = // board[Y][X]
{

"#+#+#+#+", //0
"+#+#+#+#", //1
"#+#+#+#+", //2
"+#+#+#+#", //3
"#+#+#+#+", //4
"+#+#+#+#", //5
"#+#+#+#+", //6
"+#+#+#+#"  //7

};

const char test[3][4] =  
{
    "ABC",
    "DEF",
    "GHI"
};


int main ()
{   
    // Main Loop
    bool running = true;
    bool noWinner = true;

    // Positional Variables
    std::string notationI; 
    piecePosition initPosition;
    std::set<std::string> validMoves;

    while (running && noWinner)
    {
        // Display the Board
        displayBoard(boardMain, 8, 8);

        // Get input 
        std::cout << "Input: ";
        std::cin >> notationI;

        if (notationI == "QQ")
        {
            break;
        }
        // Parse & Validate Input 
        initPosition = getInitPosition(notationI);
        std::cout << "xPos: " << initPosition.xPosition << '\n';
        std::cout << "yPos: " << initPosition.yPosition << '\n';

        std::cout << "Current Piece: " << boardMain[initPosition.yPosition][initPosition.xPosition] << "\n";

        // Display valid moves
        validMoves = getValidMoves(boardMain, initPosition);

        std::cout << "Valid Moves:\n";
        for (auto s : validMoves)
        {
            std::cout << s << '\n'; 
        }

        std::cout << "-----------------\n";
        // Return new position
    }


    return 0;
}

