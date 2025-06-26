class Solution {
public:
int solve(vector<int>& nums, int i, int n, vector<int> &dp) 
{
        if (i > n) return 0;
        // Check if the result for the current index is already computed
        if (dp[i] != -1) return dp[i];
        
        // Option 1: Rob the current house and move to the house after the next one
        int robCurrent = nums[i] + solve(nums, i + 2, n,dp);
        
        // Option 2: Skip the current house and move to the next one
        int skipCurrent = solve(nums, i + 1, n,dp);
        
        // Return the maximum of both options
        return dp[i]= max(robCurrent, skipCurrent);
    }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        
        if(n==1) return nums[0];

        if(n==2) return max(nums[0],nums[1]);

        vector<int> dp1(n,-1);  // n for 0  based index
        //taking oth index house
        int case1= solve(nums,0,n-2,dp1);  // excluding n-1th elemt or last elemnt.

        vector<int>dp2(n+1,-1);  // n+1 for 1 based index

        //taking  1th index we can include the last elemnt
        int case2=solve(nums,1,n-1,dp2);

        return max(case1,case2); 


    }
};