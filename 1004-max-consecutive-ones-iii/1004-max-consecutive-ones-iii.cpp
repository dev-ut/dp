class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
       int n = nums.size();
        int i = 0;
        int j = 0;
        int mxlength = 0;

        while(j < n)
        {
            // wok according to the given nums
            if(nums[j] == 1)
            {
                j++; // krte rho 
            }
            else
            {
                // jab 0 ho jye 
                if(k > 0)
                {
                    k--; // maan lo ki tumne flip kr diya 
                    j++;
                }
                else
                {
                    // window invalid ho gyi, answer update
                    mxlength = max(mxlength, j - i);

                    // we will shrink the i till we get the 0
                    while(nums[i] == 1) i++;

                    // i will stand at 0
                    i++;
                    k++;   // as we are making 1 to the 0 i is standing at
                }
            }
        }

        mxlength = max(mxlength, j - i);
        return mxlength; 
    }
};