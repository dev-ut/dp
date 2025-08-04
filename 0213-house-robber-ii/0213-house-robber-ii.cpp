class Solution {
public:
int solve(vector<int>& nums, int indx, int n,vector<int>&dp) 
{
        if (indx > n) return 0;
        // Check if the result for the current index is already computed
        if(dp[indx]!=-1)return dp[indx];
        
        // Option 1: Rob the current house and move to the house after the next one
        int robCurrent = nums[indx] + solve(nums, indx + 2, n,dp);
        
        // Option 2: Skip the current house and move to the next one
        int skipCurrent = solve(nums, indx+ 1,n,dp);
        
        // Return the maximum of both options
        return dp[indx]= max(robCurrent, skipCurrent);
    }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        
        if(n==1) return nums[0];

        if(n==2) return max(nums[0],nums[1]);
        // when we are not taking the last elemnt as we are taking the first elemnt coz ther aye adjacent  
        vector<int>dp1(n+1,-1);
        int case1= solve(nums,0,n-2,dp1);
        //we are not taking the first elemnt as we are taking the last elment 
        vector<int>dp2(n+1,-1); 
        int case2= solve(nums,1,n-1,dp2);

        return max(case1,case2);
    }
};