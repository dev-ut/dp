class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
       if(n==1) return nums[0];

    vector<int>dp(n+1,0);

    dp[0]=0;
    dp[1]=nums[0];

    for(int i=2;i<=n;i++)
    {
        int robcurrent=nums[i-1]+dp[i-2];
        int skipcurrrent=dp[i-1];

        dp[i]=max(robcurrent,skipcurrrent);
    }

    return dp[n];
    }
};