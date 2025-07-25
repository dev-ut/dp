class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
         int n=nums.size();
         vector<int> ans;
         unordered_map<int,int> mp;

         for(int i=0;i<n;i++)
         {
            int rem= target-nums[i];

            if(mp.find(rem)!=mp.end())
            {
               ans.push_back(mp[rem]);
               ans.push_back(i);
            }
            else
            {
                mp[nums[i]]=i;   // yahn pr we just linked key as value and value as index 
            }
         }
         return ans;
    }
};