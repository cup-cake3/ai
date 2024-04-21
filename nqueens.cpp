#include <bits/stdc++.h>
using namespace std;

void solve(int col, vector<string> &board, vector<vector<string>> &ans,
           vector<int> &leftRow, vector<int> &upperDiag,
           vector<int> &lowerDiag, int n)
{

    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[n - 1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiag[row + col] = 1;
            upperDiag[n - 1 + col - row] = 1;
            solve(col + 1, board, ans, leftRow, upperDiag, lowerDiag, n);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiag[row + col] = 0;
            upperDiag[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    vector<int> leftRow(n, 0);
    vector<int> upperDiag(2 * n - 1, 0);
    vector<int> lowerDiag(2 * n - 1, 0);

    solve(0, board, ans, leftRow, upperDiag, lowerDiag, n);
    return ans;
}

int main()
{
    int n;
    cout << "enter n";
    cin >> n;

    vector<vector<string>> ans = solveNQueens(n);
    if (ans.empty())
    {
        cout << "nah mate, shoo";
        return 0;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
}