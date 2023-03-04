#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
  string name1,name2;
  cout << "Welcome to TicTacToe "<<endl;

  cout << "Player X, Enter your name: ";
  cout << "Player O, Enter your name: ";
  
  char board[BOARD][BOARD] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  char player = 'X';
  int row, col;

  // Game loop
  while (true)
  {
    // Print current board state
    printBoard(board);

    // Get player move
    cout << "Player " << player << ", enter row (1-" << BOARD << "): ";
    cin >> row;
    cout << "Player " << player << ", enter column (1-" << BOARD << "): ";
    cin >> col;

    // Check that row and column are within range
    if (row < 1 || row > BOARD || col < 1 || col > BOARD)
    {
      cout << "Invalid row or column. Please try again." << endl;
      continue; // go back to the start of the loop
    }

    // Update board with player move
    board[row - 1][col - 1] = player;

    // Check for win condition
    bool win = false;
    for (int i = 0; i < BOARD; i++)
    {
      // Check row
      if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
      {
        win = true;
      }
      // Check column
      if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
      {
        win = true;
      }
    }
    // Check diagonal
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
      win = true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
      win = true;
    }

    if (win)
    {
      cout << "Player " << player << " wins!" << endl;
      printBoard(board);
      break;
    }

    // Check for tie condition
    bool tie = true;
    for (int row = 0; row < BOARD; row++)
    {
      for (int col = 0; col < BOARD; col++)
      {
        if (board[row][col] == ' ')
        {
          tie = false;
        }
      }
    }

    if (tie)
    {
      cout << "Tie game!" << endl;
      printBoard(board);
      break;
    }

    // Switch player turn
    player = (player == 'X') ? 'O' : 'X';
  }

  return 0;
}
