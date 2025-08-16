class Solution {
public:
    int findMin(vector<int>& nums) 
    {
         int n=nums.size();
         int lo=0;
         int hi=n-1;
         int ans=INT_MAX;
         while(lo<=hi)
         {
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<=nums[hi])  // to iska matlab hai ye already sorted hai ismen jaioge to you will eventually get larger no go to other parts
            {
                ans=min(ans,nums[mid]);
                hi=mid-1;
            }
            else
            {
                ans=min(ans,nums[mid]);
                lo=mid+1;
            }
         }
         return ans;
    }
};