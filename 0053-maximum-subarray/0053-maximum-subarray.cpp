class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
// Initialize the maximum sum as the first element
    int max_sum = nums[0];
    // Initialize the current sum as the first element
     int current_sum = nums[0];
    // Start iterating from the second element
    for(int i = 1; i < nums.size(); i++) 
    { if(current_sum + nums[i] > nums[i]) 
        {
            current_sum = current_sum + nums[i];
        } 
        else 
        {
            current_sum = nums[i];
        }

        // Update max_sum with an if-else statement
        if(current_sum > max_sum) 
        {
            max_sum = current_sum;
        }
    }
    
    return max_sum;
        
    }
};