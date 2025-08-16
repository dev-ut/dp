class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int n=nums.size();

        int lo=0;
        int hi=n-1;
        if(n == 1) return 0;  // single lemnt is always a peak elment  and yes agr ye nhi rakhoge to when array size is 1 mid will go out of buffer
        while(lo<=hi)
        {
           int mid=lo+(hi-lo)/2;
           if(mid==0)// ye tb hoga jb sorted in descending order
           {
             if(nums[mid]>nums[mid+1])
              {
                return mid;
              }
              else
              {
                lo=mid+1;
              }
           }

           if(mid==n-1)  // ye kab ayega when u ll haveelment sorted in ascendommg order
           {
              if(nums[mid]>nums[mid-1])
              {
                return mid;
              }
              else
              {
                hi=mid-1;
              }
           }
          else if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
           {
            return mid;
           }
           else if(nums[mid]<nums[mid+1])
           {
            lo=mid+1;
           }
           else
           {
            hi=mid-1;
           }
        }
        return -1;
    }
};