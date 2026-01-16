class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
       // since the no are in series so theres a concept 
       int n=nums.size();
       int ssum=n*(n+1)/2;
       // now arry elmnt sum 
       int sum=0;
       for(int i=0;i<n;i++)
       {
         sum=sum+nums[i];
       } 
       // missing no will be 
       return {ssum-sum};
    }
};