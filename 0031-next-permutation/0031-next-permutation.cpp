class Solution {
public:
    void nextPermutation(vector<int>& nums) 
{
    int n = nums.size();
    int pivot = -1;

    // Step 1: Find pivot index jaha nums[i] < nums[i+1]
    for (int i = n - 2; i >= 0; i--) 
    {
        if (nums[i] < nums[i + 1]) 
        {
            pivot = i;
            break;
        }
    }

    if (pivot != -1) 
    {
        // Step 2: Find smallest number greater than nums[pivot] from right
        for (int i = n - 1; i > pivot; i--) 
        {
            if (nums[i] > nums[pivot]) 
            {
                swap(nums[i], nums[pivot]);
                break;
            }
        }
    }

    // Step 3: Reverse the right part of the array after pivot
    reverse(nums.begin() + pivot + 1, nums.end());
}
};