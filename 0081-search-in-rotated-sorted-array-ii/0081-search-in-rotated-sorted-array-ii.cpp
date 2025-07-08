class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
      int n = nums.size();
    if (n == 0) return false;
    int lo = 0;
    int hi = n - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return true;

        if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) 
        { // Handling duplicates   // this is extra chhez  nums = [1,0,1,1,1], target = 0
            lo++;
            hi--;
        } 
        else if (nums[lo] <= nums[mid]) 
        { // Left part is sorted
            if (nums[lo] <= target && target < nums[mid]) { // Target is in the left part
                hi = mid - 1;
            } else 
            {
                lo = mid + 1; // Target is in the right part
            }
        } else { // Right part is sorted
            if (nums[mid] < target && target <= nums[hi]) { // Target is in the right part
                lo = mid + 1;
            } else {
                hi = mid - 1; // Target is in the left part
            }
        }
    }

    return false; // Target not found
    }
};