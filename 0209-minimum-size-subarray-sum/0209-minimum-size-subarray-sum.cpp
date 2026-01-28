class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
      int i=0;
      int j=0;
      int mncount=INT_MAX;
      int sum=0;
      int n=nums.size();
      while(j<n)
      {
        sum+=nums[j];
        while(sum>=target && i<=j)
        {
            mncount=min(mncount,j-i+1);
            sum=sum-nums[i];
            i++; // shirnk the i 
        }
        j++;
      }
      if(mncount==INT_MAX) return 0;
      else return mncount;  
    }
};