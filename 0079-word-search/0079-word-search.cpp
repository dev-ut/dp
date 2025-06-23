class Solution {
public:
    void solve(vector<vector<char>>& board, int row, int col, string& word, int idx, bool& flag) 
    {
        if (idx == word.size()) 
        {
            flag = true;
            return;
        }

        int n = board.size();
        int m = board[0].size();

        // Out of bounds or mismatch
        if (row < 0 || col < 0 || row >= n || col >= m || board[row][col] != word[idx])
            return;

        // Mark as visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Move in all 4 directions

        // Right
        solve(board, row, col + 1, word, idx + 1, flag);

        // Down
        solve(board, row + 1, col, word, idx + 1, flag);

        // Left
        solve(board, row, col - 1, word, idx + 1, flag);

        // Up
        solve(board, row - 1, col, word, idx + 1, flag);

        // Backtrack
        board[row][col] = temp;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    bool flag = false;
                    solve(board, i, j, word, 0, flag);
                    if (flag) return true;
                }
            }
        }
        return false;
    }
};
