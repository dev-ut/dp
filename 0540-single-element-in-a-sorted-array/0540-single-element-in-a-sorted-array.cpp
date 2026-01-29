class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
    int n = nums.size();
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi) 
    {
        int mid = lo + (hi - lo) / 2;
        
        // Check if mid is the single non-duplicate element
        if ((mid == 0 || nums[mid] != nums[mid - 1]) && (mid == n - 1 || nums[mid] != nums[mid + 1]))  
            return nums[mid];
        else if (mid % 2 == 0 && nums[mid] == nums[mid + 1]) 
            lo = mid + 1;
        else if (mid % 2 != 0 && nums[mid] == nums[mid - 1]) 
            lo = mid + 1;
        else 
            hi = mid - 1;
    }
     return -1;
    }
};