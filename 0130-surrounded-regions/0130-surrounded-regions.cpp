class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis) 
    {
        vis[r][c] = 1; // mark visited

        int n = board.size();
        int m = board[0].size();

        // UP
        if (r - 1 >= 0 && board[r - 1][c] == 'O' && vis[r - 1][c] == 0) {
            dfs(r - 1, c, board, vis);
        }
        // DOWN
        if (r + 1 < n && board[r + 1][c] == 'O' && vis[r + 1][c] == 0) {
            dfs(r + 1, c, board, vis);
        }
        // LEFT
        if (c - 1 >= 0 && board[r][c - 1] == 'O' && vis[r][c - 1] == 0) {
            dfs(r, c - 1, board, vis);
        }
        // RIGHT
        if (c + 1 < m && board[r][c + 1] == 'O' && vis[r][c + 1] == 0) {
            dfs(r, c + 1, board, vis);
        }
    }

    void solve(vector<vector<char>>& board) 
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Pehle first row aur last row se DFS chalao
        for (int j = 0; j < m; j++) 
        {
            if (board[0][j] == 'O' && vis[0][j] == 0) 
            {
                dfs(0, j, board, vis);
            }
            if (board[n - 1][j] == 'O' && vis[n - 1][j] == 0) 
            {
                dfs(n - 1, j, board, vis);
            }
        }

        // Pehle col aur last col se DFS chalao
        for (int i = 0; i < n; i++) 
        {
            if (board[i][0] == 'O' && vis[i][0] == 0) 
            {
                dfs(i, 0, board, vis);
            }
            if (board[i][m - 1] == 'O' && vis[i][m - 1] == 0) 
            {
                dfs(i, m - 1, board, vis);
            }
        }

        // Jo 'O' visited nahi hai unko 'X' bana do
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (board[i][j] == 'O' && vis[i][j] == 0) 
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
