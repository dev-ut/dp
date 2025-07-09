class Solution {
public:
    // Recursive function to generate subsets
    void subset(vector<int>& nums, vector<int> ans, int index, vector<vector<int>>& fans) {
        // Base Case: If we have processed all elements, add the current output to the answer
        if (index >= nums.size()) 
        {
            fans.push_back(ans);
            return;
        }
              ans.push_back(nums[index]);
             subset(nums,ans,index+1,fans);
             ans.pop_back();  // backtrack
             //notake    // iska caase pehel likhoge to  u dont have to write pop back 
               subset(nums,ans,index+1,fans);

              //take
              

            //  ans.pop_back(); // backtrack
             

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> fans; // Final output storage
        vector<int> ans;     // Temporary output storage
        int index = 0;
        subset(nums, ans, index, fans); // Start generating subsets
        return fans;
    }
};