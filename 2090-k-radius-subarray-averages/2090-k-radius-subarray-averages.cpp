class Solution {
public:
vector<int> getAverages(vector<int>& nums, int k) 
{
    int n = nums.size();
    vector<int> ans(n, -1);

    if(n < 2*k + 1) return ans;

    long long pwsum = 0;

    // first window
    for(int i = 0; i < 2*k + 1; i++)
        pwsum += nums[i];

    ans[k] = pwsum / (2*k + 1);

    int i = 1;
    int j = 2*k + 1;
    int center = k + 1;

    while(j < n)
    {
        pwsum = pwsum - nums[i-1] + nums[j];
        ans[center] = pwsum / (2*k + 1);

        i++;
        j++;
        center++;
    }

    return ans;
}
};
