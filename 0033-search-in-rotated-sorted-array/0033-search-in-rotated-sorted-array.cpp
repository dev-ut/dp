class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n=nums.size();

        int lo=0;
        int hi=n-1;

        while(lo<=hi)
        {
            // we will serch for sorted parts  // suppose right sorted

            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;

            if(nums[mid]<nums[hi])  // right sorted
            { 
                if(nums[mid]<=target && nums[hi]>=target)  // yes the target ies here
                {
                    lo=mid+1;
                }
                else
                {
                    hi=mid-1;
                }
            }
            else   // left soretd
            {
               if(nums[mid]>=target && nums[lo]<=target)  // ye yhi milega 4,5,6,7,0,1,2  // target=6
               {
                hi=mid-1;
               }
               else
               {
                lo=mid+1;
               }
            }
        }
        return -1;
    }
};