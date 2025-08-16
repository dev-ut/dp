class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        if (n == 0) return false;
        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) 
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return true;

            // Handle duplicates
            if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) 
            {
                lo++;
                hi--;
            } 
            else if (nums[mid] <= nums[hi])   // ✅ Right part sorted
            {   
                if (nums[mid] < target && target <= nums[hi]) 
                {   // Target right me hai
                    lo = mid + 1;
                } 
                else 
                {   // Target left me hoga
                    hi = mid - 1;
                }
            } 
            else    // ✅ Left part sorted
            {   
                if (nums[lo] <= target && target < nums[mid]) 
                {   // Target left me hai
                    hi = mid - 1;
                } 
                else 
                {   // Target right me hoga
                    lo = mid + 1; 
                }
            }
        }
        return false; 
    }
};
