class Solution {
public:
 int solve(vector<int>& nums,int indx,int n,vector<int>&memo)
 {
     if(indx>=n) return 0;
     if(memo[indx]!=-1) return memo[indx];

     int robcurrent=nums[indx]+solve(nums,indx+2,n,memo);
     int skipcurrent=solve(nums,indx+1,n,memo);
     
     memo[indx]=max(robcurrent,skipcurrent);
     return memo[indx];
 }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>memo(n+1,-1);
        return solve(nums,0,n,memo);
    }
};