#include "say.h"

piecePosition getInitPosition(const std::string strNotation)
{
    int x_pos = (int)(strNotation[1]) - '0';
    int y_pos = (int)tolower(strNotation[0]) - 'a';

    return {x_pos - 1, y_pos}; // Decrement x_pos because arrays are 0-indexed
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