#include <iostream>
using namespace std;

#define N 9 


bool is_possible(int board[][N], int row, int col, int val)
{
    // check if the column is valid
    for (int i = 0; i < N; i++)
    {
        if (board[i][col] == val)
        {
            return false;
        }
    }
    // check if the row is valid
    for (int i = 0; i < N; i++)
    {
        if (board[row][i] == val)
        {
            return false;
        }
    }
    // check if the 3x3 matrix is valid
    int startRow = 3 * (row / 3); //get if it is the 0,1 or 2 3x3 square then *3
    int startCol = 3 * (col / 3);
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (board[i][j] == val)
            {
                return false;
            }
        }
    }
    // if every test passed
    return true;
}
bool solve(int board[][N], int row, int col)
{
    //to check if we are outisde the 9x9 gird
    if (col == N)
    {

        if (row == N - 1)
        {
            return true; // we have filled the last square 
            // and add 1 to col (sudoku solved)
        }
        // we are at the end of a column
        col = 0;
        row++;
    }

    if (board[row][col] != 0) // Already filled, solve for next square
    {
        return solve(board, row, col + 1);
    }

    for (int x = 1; x <= N; x++) //try every value between 1 and 9
    {
        if (is_possible(board, row, col, x))
        {
            board[row][col] = x;
            if (solve(board, row, col + 1)) // try x and check if it works
            {
                return true;
            }

        }
        board[row][col] = 0; // previous x value didn't work
        // reset and try another x
    }

    return false; // We are in a dead end
    // can't solve the sudoku with current values
}
void print_board(int board[][N]) 
{

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            cout << board[row][col] << " ";
            if ((col + 1) % 3 == 0 && col < N - 1)
            {
                cout << "| ";
            }
        }
        cout << endl;
        if ((row + 1) % 3 == 0 && row < N - 1) {
            cout << "------+-------+------" << endl;
        }
    }
}

int main()
{
    
    int board[N][N] = {
        {4, 2, 0, 5, 8, 6, 9, 3, 3},
        {9, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 0, 0, 0, 0, 0, 4, 0},
        {0, 5, 0, 4, 0, 0, 0, 0, 0},
        {3, 4, 9, 8, 1, 0, 0, 6, 0},
        {8, 0, 1, 9, 6, 2, 3, 5, 0},
        {0, 0, 0, 0, 0, 1, 5, 0, 0},
        {0, 0, 8, 7, 4, 0, 1, 0, 6},
        {1, 3, 2, 6, 0, 0, 0, 9, 0}
    };
    print_board(board);



    bool solved = solve(board, 0, 0);

    if (solved) {
        cout << "\nSolved Sudoku:" << endl;
        print_board(board);
    }
    else {
        cout << "\nNo solution exists." << endl;
    }

    return 0;
}