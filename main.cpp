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

const char boardBase[8][9] =
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

const std::string test[] = 
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
        displayBoard();

        // Get input 
        std::cin >> notationI;
        // Parse & Validate Input 
        initPosition = getInitPosition(notationI);

        std::cout << test[initPosition.xPosition][initPosition.yPosition] << "\n";

        // Return new position
    }


    return 0;
}

