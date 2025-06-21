class Solution {
public:
int solve(vector<int>& cost,int indx,int n,vector<int>&dp)
{
    if(indx>=n)
    {
        return 0;
    }
      if(dp[indx]!=-1) return dp[indx];

      int onestep=cost[indx]+ solve(cost,indx+1,n,dp);
      int twostep=cost[indx]+ solve(cost,indx+2,n,dp);

      return dp[indx]= min(onestep,twostep);
}
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int count=-0;
        int n=cost.size();
        vector<int>dp(n+1,-1);
       
        return min(solve(cost,0,n,dp), solve(cost,1,n,dp));
    }
};