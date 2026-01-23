class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // since it is a sorted arry we can apply the method of bs typye alogoritha 
        int lo=0;
        int hi=nums.size()-1;

        while(lo<=hi)
        {
            int sum=nums[lo]+nums[hi];
            if(sum==target)
            {
                return {lo+1,hi+1};
            }
            else if(sum>target)
            {
                hi--;
            }
            else
            {
                lo++;
            }
        }
        return {};
    }
};