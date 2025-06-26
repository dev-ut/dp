class Solution {
public:
    int rob(vector<int>& nums) 
    {
      // tabulation 
      int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n, 0);

    // Base cases
    dp[0] = nums[0];                     // Pehle ghar ko lootna
    dp[1] = max(nums[0], nums[1]);       // Do ghar mein se jo zyada paisa de // its a deciding step jo bda no dega samjo whi se chlu kiya hai 


      for(int i=2;i<n;i++)
      {
        int robCurrent = nums[i] + dp[i - 2];   // current ghar + i-2 tak ka max
        int skipCurrent = dp[i - 1];            // current ghar skip
        dp[i] = max(robCurrent, skipCurrent);   // dono mein se best option

      }
      return dp[n-1];    
    }
};