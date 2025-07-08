class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
    if (n == 0) return -1;
    int lo = 0;
    int hi = n - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;

        if (nums[lo] == target) return lo;  // Check if lo is the target
        
        if (nums[lo] <= nums[mid]) { // it means it's a left sorted part
            if (nums[lo] <= target && target < nums[mid]) { // if so, the value lies in the left part only
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[hi]) { // it means it lies in the right sorted part
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }

    return -1;
    }
};