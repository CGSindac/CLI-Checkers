#include <iostream>
#include "include/say.h"

char boardMain[8][9] =
{

"B+B+B+B+", //0
"+B+B+B+B", //1
"B+B+B+B+", //2
"+#+#+#+#", //3
"#+#+#+#+", //4
"+W+W+W+W", //5
"W+W+W+W+", //6
"+W+W+W+W"  //7

};

// "B+B+B+B+",
// "+#+#+B+B",
// "B+B+B+B+",
// "+#+B+#+#",
// "#+B+B+#+",
// "+W+W+W+W",
// "W+W+#+#+",
// "+W+W+W+W"
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
    int turnCount = 1;
    bool whiteWin = true;

    char currentPiece;

    int blackPieceCount;
    int whitePieceCount;

    // Positional Variables
    std::string notationI, action; 
    piecePosition initPosition;

    // Set to store Valid moves
    std::set<std::string> validMoves;
    
    
    /*----Main Game Loop----*/
    while (true)
    {   
        // Get number of pieces for checking
        blackPieceCount = countPieces(boardMain, BLACK, XMAX, YMAX);
        whitePieceCount = countPieces(boardMain, WHITE, XMAX, YMAX);

        if (blackPieceCount == 0)
        {
            whiteWin = true;
            break;
        }else if (whitePieceCount == 0)
        {
            whiteWin = false;
            break;
        }

        // Display the Board
        std::cout << "\n---------------------\n";
        std::cout << "TURN #" << turnCount << ": " << (turnCount % 2 == 0 ? "BLACK MOVE\n" : "WHITE MOVE\n");
        std::cout << "# WHITE: " << whitePieceCount << " # BLACK: " << blackPieceCount << "\n";
        displayBoard(boardMain, 8, 8);

        // Get input 
        do{
            std::cout << "Input: ";
            std::cin >> notationI; if (notationI == "QQ") break;

            initPosition = getPosition(notationI);
            currentPiece = boardMain[initPosition.yPosition][initPosition.xPosition];

            // First Check if proper Black or White pieces are chosen
            if (turnCount % 2 != 0  && (currentPiece != WHITE && currentPiece != QWHITE))
            {   
                std::cout << "Please select a WHITE piece\n";
                continue;
            } else if (turnCount % 2 == 0  && (currentPiece != BLACK && currentPiece != QBLACK))
            {
                std::cout << "Please select a BLACK piece\n";
                continue;
            }

            // Get action from input notation
            action = notationI.substr(2);

            validMoves = getValidMoves(boardMain, initPosition);

            // Check if selected piece has valid actions
            if (validMoves.empty())
            {
                std::cout << "Piece has no valid action, choose another one.\n";
                continue;
            }

            auto it = validMoves.find(action);

            if (it != validMoves.end()) break;
            else
            {
                std::cout << "!!Not A valid move!!\n";

                std::cout << "Valid Moves:\n";
                for (auto s : validMoves)
                {
                    std::cout << s << '\n'; 
                }

                continue;
            } 
            std::cout << "---------------------\n";
            std::cout << "\n";
            break;

        } while (true);
        
        if (notationI == "QQ") break;
        
        if (action[0] == 'm') movePiece(boardMain, initPosition, action);
        else takeAction(boardMain, initPosition, action);

        updateBoardPieces(boardMain);
        std::cout << "---------------------\n";
        ++turnCount;
        // Return new position
    }

    std::cout << "\n!!!---WINNER IS " << (whiteWin ? "WHITE" : "BLACK") << "---!!!\n";

    return 0;
}

