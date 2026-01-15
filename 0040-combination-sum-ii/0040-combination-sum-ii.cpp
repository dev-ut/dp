class Solution {
public:
void cosum(vector<int>& candidates, int target,vector<vector<int>>&fans,vector<int>&ans,int indx,int n)
{
    
    if(target==0)
    {
        fans.push_back(ans);
        return ;
    }
    if(indx==n ||target<0) return ;
    // since we can take it multiple times 
    ans.push_back(candidates[indx]);
    cosum(candidates,target-candidates[indx],fans,ans,indx+1,n);
    ans.pop_back();
    
    //skipping duplicates
    while(indx+1<n && candidates[indx]==candidates[indx+1])indx++;

    // not atke condition 
    cosum(candidates,target,fans,ans,indx+1,n);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>fans;
        vector<int>ans;
        int n=candidates.size();
        cosum(candidates,target,fans,ans,0,n);
        return fans;
    }
};