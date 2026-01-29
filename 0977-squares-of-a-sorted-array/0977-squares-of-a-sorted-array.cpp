class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>ans(n);
        int i=0;
        int j=nums.size()-1;
        int k=nums.size()-1;  // isko piche se isliye le rha kyunki jo pehla elemnt hum dalneg wo maximum hoga 
        while(i<=j)
        {
            int left=nums[i]*nums[i];
            int right=nums[j]*nums[j];
            if(left<right)
            {
               ans[k--]=right;
               j--;
            }
            else
            {
              ans[k--]=left;
              i++;
            }
        }
        return ans;

    }
};