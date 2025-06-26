class Solution {
public:
   int minimumTotal(vector<vector<int>>& triangle) 
{
    int n = triangle.size();
    int dp[205][205];  // static 2D array (max triangle size = 200)

    // Base case: last row copy karo
    for(int j = 0; j < triangle[n-1].size(); j++) 
    {
        dp[n-1][j] = triangle[n-1][j];
    }

    // Bottom-up fill
    for(int i = n-2; i >= 0; i--) 
    {
        for(int j = 0; j <= i; j++) 
        {
            int down = dp[i+1][j];
            int diag = dp[i+1][j+1];
            dp[i][j] = triangle[i][j] + min(down, diag);
        }
    }

    return dp[0][0];
}

};