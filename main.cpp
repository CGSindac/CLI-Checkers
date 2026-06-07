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
"W+W+W+#+",
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
    std::string notationI, action; 
    piecePosition initPosition;
    std::set<std::string> validMoves;
    

    while (running && noWinner)
    {
        // Display the Board
        displayBoard(boardMain, 8, 8);

        // Get input 
        std::cout << "Input: ";
        std::cin >> notationI;

        initPosition = getPosition(notationI);
        action = notationI.substr(2);

        // Display valid moves
        validMoves = getValidMoves(boardMain, initPosition);

        // Check if action is valid
        auto it = validMoves.find(action);
        if (it != validMoves.end()) movePiece(boardMain, initPosition, action);
        else std::cout << "Not A valid move\n";

        std::cout << "Valid Moves:\n";
        for (auto s : validMoves)
        {
            std::cout << s << '\n'; 
        }

        std::cout << "Action: "<< action << "\n";

        if (notationI == "QQ")
        {
            break;
        }
        // Parse & Validate Input 
        
        

        std::cout << "Current Piece: " << boardMain[initPosition.yPosition][initPosition.xPosition] << "\n";

        
        

        

        std::cout << "-----------------\n";
        // Return new position
    }


    return 0;
}

