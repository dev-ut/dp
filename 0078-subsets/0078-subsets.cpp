class Solution {
public:
void subset(vector<int>& nums,vector<vector<int>> &fans, vector<int>&ans,int indx)
{
    if(indx>=nums.size())
    {
     fans.push_back(ans);
     return ;
    }

    // take case
    ans.push_back(nums[indx]);
    subset(nums,fans,ans,indx+1);
    // backtrack after we reach the base case 
    ans.pop_back();
    // not take skip current indx
    subset(nums,fans,ans,indx+1);
}
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> fans;
        vector<int>ans;
        subset(nums,fans,ans,0);
        return fans;
    }
};