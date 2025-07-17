class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int n=arr.size();
        int prevsum=0;
        int currsum=0;

        for(int i=0;i<k;i++)
        {
            prevsum+=arr[i];
        }
        int count=0;
        if(prevsum/k>=threshold) count++;
        int i=1;
        int j=k;

        while(j<n)
        {
            currsum=prevsum-arr[i-1]+arr[j];


            if(currsum/k>=threshold) count++;


            prevsum=currsum;
            i++;
            j++;
        }
        return count;

    }
};