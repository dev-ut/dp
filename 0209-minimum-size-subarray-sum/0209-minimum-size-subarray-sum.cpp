class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int i = 0;
        int j = 0;
        int sum = 0;
        int n = nums.size();
        int mncount = INT_MAX; // min length track karne ke liye

        while (j < n)
        {
            sum = sum + nums[j]; // nums[j] add karo

            // Jab tak sum >= target ho, window shrink karte raho
            while (i <= j && sum >= target)
            {
                mncount =min(mncount, j - i + 1); // min length update
                sum = sum - nums[i];
                i++;
            }

            j++; // window expand
        }

        if (mncount != INT_MAX) return mncount; // agar valid mila
        return 0; // nahi mila to 0
    }
};
