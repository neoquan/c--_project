#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;


// Tik-tak-toe board is like this
//  X | O |  
// ---+---+---
//    | X |  
// ---+---+---
//  O |   |  


// Print the board
void printBoard(const vector<vector<char>>& board)
{
    cout << "\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // If cell is empty ('\0'), print a space ' '.
            // Otherwise print 'X' or 'O'.
            cout << " " << (board[i][j] == '\0' ? ' ' : board[i][j]);
            // If it’s not the last column → print " |".
            if (j < SIZE - 1) cout << " |";
        }
        cout << "\n";
        // If it’s not the last row, print divider line.
        if (i < SIZE - 1) cout << "---+---+---\n";
    }
    cout << "\n";
}


// Check winner
char checkWinner (const vector<vector<char>>& board)
{
    // Rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != '\0' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
            return board[i][0];
    }

    // Columns

    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] != '\0' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return board[0][j];
    }

    // Diagonals

    if (board[0][0] != '\0' && board[0][0] == board[1][1] && board[1][1] ==board[2][2])
        return board[0][0];

    if (board[0][2] != '\0' && board[0][2] == board[1][1] && board[0][2] ==board[2][0])
        return board[0][2];
}
