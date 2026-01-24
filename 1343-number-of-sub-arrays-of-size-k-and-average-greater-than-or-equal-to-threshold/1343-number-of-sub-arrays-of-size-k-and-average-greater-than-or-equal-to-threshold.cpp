class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
     int n=arr.size();
     int prevwsum=0;
     int count=0;
     for(int i=0;i<k;i++) 
     {
      prevwsum+=arr[i];
     }
     if(prevwsum/k>=threshold) count++;
     int i=1;
     int j=k;
     int curwsum=0;
     while(j<n)
     {
       curwsum=prevwsum-arr[i-1]+arr[j];
       if(curwsum/k>=threshold) count++;
       prevwsum=curwsum;
       i++;
       j++;
     }  

     return count;
    }
};