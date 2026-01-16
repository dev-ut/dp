class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
     // using dutch flag algoritham
        int lo=0;
        int mid=0;
        int hi=nums.size()-1;

        while(mid<=hi)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[lo]);
                lo++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else {
                swap(nums[mid],nums[hi]);
                hi--;
            }
        }
        
    }
};