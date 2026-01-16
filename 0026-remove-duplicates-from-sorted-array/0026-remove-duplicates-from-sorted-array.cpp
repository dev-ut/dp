class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        // we are going to use static and moving pointer approch
        int i=0;
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]!=nums[j])
            {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1; 
    }
};