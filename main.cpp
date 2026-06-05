#include <iostream>
#include "include/say.h"

char boardA[8][9] =
{

"B+B+B+B+",
"+B+B+B+B",
"B+B+B+B+",
"+#+#+#+#",
"#+#+#+#+",
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

    while (running && noWinner)
    {
        // Display the Board
        displayBoard(boardBase, 8, 8);

        // Get input 
        std::cout << "Input: ";
        std::cin >> notationI;

        if (notationI == "QQ")
        {
            break;
        }
        // Parse & Validate Input 
        initPosition = getInitPosition(notationI);

        std::cout << boardBase[initPosition.xPosition][initPosition.yPosition] << "\n";

        // Return new position
    }


    return 0;
}

