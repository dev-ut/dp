class Solution {
public:
   void subset(vector<int>& nums, vector<int> ans, vector<vector<int>>& fans, int idx, int n) {
    // base case
   if(idx==n)
   {
     fans.push_back(ans);
     return ;
   }

   // take 
   ans.push_back(nums[idx]);
   subset(nums,ans,fans,idx+1,n);
   ans.pop_back();

   // remove duplicate
   while(idx+1 < n && nums[idx]==nums[idx+1]) idx++;
   
   //not take 
   subset(nums,ans,fans,idx+1,n);
}


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the array to handle duplicates
        int n = nums.size();
        vector<int> ans; // Temporary vector to store subsets
        vector<vector<int>> fans; // Final answer
        subset(nums, ans, fans, 0, n);
        return fans;
    }
};

