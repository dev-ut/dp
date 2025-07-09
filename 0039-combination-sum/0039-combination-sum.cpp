class Solution {
public:
void cosum(vector<int>& nums,vector<int> ans,vector<vector<int>>& fans,int indx, int target,int n)
{
    if(indx==n || target<0)
    {
        return;
    }
    if(target==0)
    {
        fans.push_back(ans);
        return;
    }
    // take 
    ans.push_back(nums[indx]);
    cosum(nums,ans, fans,indx,target-nums[indx],n);  // we are not increasing the indx as we can take same value multiple time 
    ans.pop_back();

    //not take 
    cosum(nums,ans, fans,indx+1,target,n); 


}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        int n=nums.size();
        vector<vector<int>>fans;
        vector<int> ans;
        cosum(nums,ans, fans,0,target,n);
        return fans;
        
    }
};