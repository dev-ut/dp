class Solution {
public:
// int solve(vector<vector<int>>& grid, int r, int c, int er, int ec,vector<vector<int>> &dp) {
//     // Define a very large value for invalid paths
//         const int INF = 1e9;

//         // If out of bounds, return the large value to indicate an invalid path
//         if (r > er || c > ec) return INF;

//         // If reached the bottom-right corner, return the cell's value
//         if (r == er && c == ec) return grid[r][c];

//         // If the result is already computed, return it
//         if (dp[r][c] != -1) return dp[r][c];

//         // Recursively calculate the minimum path sum for moving right and down
//         int rightways = grid[r][c] + solve(grid, r, c + 1, er, ec, dp);
//         int downways = grid[r][c] + solve(grid, r + 1, c, er, ec, dp);

//         // Return the current cell's value plus the minimum of the right and down sums
//         return dp[r][c] = min(rightways, downways);
//     }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
       // vector<vector<int>> dp(m,vector<int>(n,-1));
       // return solve(grid, 0, 0, m - 1, n - 1,dp);

    // Create a dp table of the same size as grid
    vector<vector<int>> dp(m, vector<int>(n, -1));

    // Initialize the starting point
    dp[0][0] = grid[0][0];

    // Fill the first row
    for (int j = 1; j < n; ++j) 
    {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Fill the first column
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill the rest of the dp table
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // The result is in the bottom-right corner of the dp table
    return dp[m - 1][n - 1];
    }
};