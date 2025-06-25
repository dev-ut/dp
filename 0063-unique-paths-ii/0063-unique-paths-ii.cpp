class Solution {
public:
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
    // memoization code 
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    int dp[m][n];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            // agar cell pe obstacle hai to 0 path
            if(obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            }

            else if(i == 0 && j == 0) {
                // starting cell
                dp[i][j] = 1;
            }

            else if(i == 0) {
                // first row, left se hi aa sakte
                dp[i][j] = dp[i][j-1];
            }

            else if(j == 0) {
                // first column, upar se hi aa sakte
                dp[i][j] = dp[i-1][j];
            }

            else {
                // dono directions allowed (upar aur left)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}

};