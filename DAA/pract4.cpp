#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class NQueens {
    int n;

    public:
    NQueens(int n) {
        this->n = n;
    }

    bool isSafe(int row, int col, vector<string>& board) {

         // horizontally checking
        for(int i=0; i<n; i++)
        {
            if (board[row][i] == 'Q')
            {
                return false;
            }
        }

        // vertically checking
        for(int i=0; i<n; i++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }
        int r = row;
        // upper right
        for (int c = col; c < n, r >= 0; c++, r--)
        {
            if (board[r][c] == 'Q')
            {
                return false;
            }
        }
        // upper left
        r = row;
        for (int c = col; c >= 0, r >= 0; c--, r--)
        {
            if (board[r][c] == 'Q')
            {
                return false;
            }
        }
        // lower right
        r = row;
        for (int c = col; c < n, r < n; c++, r++)
        {
            if (board[r][c] == 'Q')
            {
                return false;
            }
        }

        // lower left
        r = row;
        for (int c = col; c >= 0, r < n; c--, r++)
        {
            if (board[r][c] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    void solve(int col, vector<string>& board, vector<vector<string> >& ans) {
        if(col == n) {
            ans.push_back(board);
            for(auto str : board)
                cout<<str<<endl;
            cout<<endl;
            return;
        }
        for(int row = 0; row<n; row++) {
            if(board[row][col] == '.' && isSafe(row, col, board)) {

                board[row][col] = 'Q';
                solve(col+1,board,ans);
                board[row][col] = '.';
            }
            if(board[row][col] == 'Q') {
                solve(col+1,board,ans);
            }
        }
    }
};

int main() {
    int n; cin>>n;
    int i,j;
    cin>>i>>j;

    NQueens nq = NQueens(n);

    vector<vector<string> > ans;
    string temp(n, '.');
    vector<string> board(n, temp);
    if(i>=0 && i<n && j<n && j>=0)
    board[i][j] = 'Q';

    nq.solve(0, board, ans);
    cout<<ans.size()<<endl;
}
