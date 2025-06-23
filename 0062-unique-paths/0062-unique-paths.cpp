class Solution {
public:
int solve(int i, int j, int r, int c, vector<vector<int>>& dp)
{
    // Out of bounds
    if(i >= r || j >= c) return 0;

    // Destination reached
    if(i == r - 1 && j == c - 1) return 1;

    // Already computed
    if(dp[i][j] != -1) return dp[i][j];

    
    int right=solve(i, j + 1, r, c, dp);// move right
    int down=solve(i + 1, j, r, c, dp); //move down

    // Store the result in dp
    return dp[i][j] =  right+down; 
}

int uniquePaths(int m, int n) 
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(0, 0, m, n, dp);
}
};

