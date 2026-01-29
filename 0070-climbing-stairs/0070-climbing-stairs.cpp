class Solution {
public:
// int solve(int n,int indx,vector<int>&memo)
// {
//     if(indx==n)
//     {
//         return 1;
//     }
//     if(indx>n) return 0;
//     if(memo[indx]!=-1) return memo[indx];
    
//     int onestep=solve(n,indx+1,memo);
//     int twostep=solve(n,indx+2,memo);
//     memo[indx]=onestep+twostep;
//     return memo[indx];

// }
    int climbStairs(int n) 
    {
      
    //   vector<int>memo(n+1,-1);
     
    //   return    solve(n,0,memo);  

    // atbulaton approch actual dp 
    vector<int>dp(n+2,-1);
    // abse cases
    dp[n]=1;
    dp[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        dp[i]=dp[i+1]+dp[i+2];
    }
    return dp[0];

    }
};