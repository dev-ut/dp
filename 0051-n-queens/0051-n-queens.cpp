class Solution {
public:
vector<vector<string>>ans;
bool isPossible(vector<string>& board,int r,int c,int n)
{
    // 3 conditions left diogobal , right digonal adn upper check 

    // Same column ke upar check
        for (int i = 0; i < r; i++) 
        {
            if (board[i][c] == 'Q') return false;
        }

        // Upper left diagonal
        int i = r - 1, j = c - 1;
        while (i >= 0 && j >= 0) 
        {
            if (board[i][j] == 'Q') return false;
            i--;
            j--;
        }

        // Upper right diagonal
        i = r - 1, j = c + 1;
        while (i >= 0 && j < n) 
        {
            if (board[i][j] == 'Q') return false;
            i--;
            j++;
        }

        return true;
}
void solve(vector<string>& board,int r,int n)
{
    if(r==n)
    {
      ans.push_back(board);
      return ;
    }

    for(int col=0;col<n;col++)
    {
        if(isPossible(board,r,col,n)==true)
        {
           board[r][col]='Q';
           solve(board,r+1,n);
           // if not backtrack 
           board[r][col]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string>board(n,string(n,'.'));
        solve(board,0,n);
        return ans;
    }
};