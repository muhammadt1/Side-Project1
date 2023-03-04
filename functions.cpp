#include "functions.h"

void printBoard(char board[BOARD][BOARD])
{
  // Print current board state
  for (int row = 0; row < BOARD; row++)
  {
    for (int col = 0; col < BOARD; col++)
    {
      cout << board[row][col];
      if (col != BOARD - 1)
      {
        cout << "|";
      }
    }
    cout << endl;
    if (row != BOARD - 1)
    {
      cout << "-----" << endl;
    }
  }
}