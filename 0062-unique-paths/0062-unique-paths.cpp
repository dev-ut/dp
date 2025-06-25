class Solution {
public:
    int uniquePaths(int m, int n) 
{
    // Tabulation
    int dp[m][n];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)  // starting cell
            {
                dp[i][j] = 1;
            }
            else if(i == 0)
            {
                dp[i][j] = dp[i][j - 1]; // pehli row
            }
            else if(j == 0)
            {
                dp[i][j] = dp[i - 1][j]; // pehla column
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // up + left
            }
        }
    }

    return dp[m - 1][n - 1];
}

};