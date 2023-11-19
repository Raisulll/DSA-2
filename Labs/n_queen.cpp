#include <iostream>
#include <vector>
using namespace std;
int c=0;
bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    for (int i = 0; i < row; ++i)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

bool printqueen(vector<vector<int>> &board, int row, int n)
{
    if (row == n)
    {
        c++;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    bool res = false;
    for (int col = 0; col < n; ++col)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 1;
            res = printqueen(board, row + 1, n);
            board[row][col] = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    printqueen(board, 0, n);
    cout<<c<<endl;  
    return 0;
}
