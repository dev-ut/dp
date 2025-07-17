class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
     {
    int n = nums.size();
    int count = 0;
    int i = 0;
    int j = 0;
    int crprd = 1; // Current product initially 1 hoga

    if (k <= 1) return 0; // Agar k 1 ya usse chhota hai, toh koi valid subarray nahi banega
    

    while (j < n) 
    {
           crprd *= nums[j]; // nums[j] ko product mein daalo
             while(i<=j && crprd >= k)   // tb tk chup chaap bs i bdhate rho and crprd mai se piche ala elemnt remove krte rho 
             {
                crprd/=nums[i];
                i++;   // shrink kr do ...
             }
        

        count=count+(j-i+1);    // coz every individua; elmnt contibutes to bne a window 
        j++;
    }
    return count;
     }
};