class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int mxi=0;
        int count=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1) 
            {
                count++;
                if(count>mxi) mxi=count;
            }
            
            else count=0;
        }
        return mxi;
    }
};