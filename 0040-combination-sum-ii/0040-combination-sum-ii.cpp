class Solution {
public:
void subset(vector<int>& nums, vector<int>& ans, vector<vector<int>>& fans, int idx, int n, int target) {
    // base case
    if (target == 0) {
        fans.push_back(ans);
        return;
    }
    
    if (idx == n || target < 0)
        return;

    // take
    ans.push_back(nums[idx]);
    subset(nums, ans, fans, idx + 1, n, target - nums[idx]);  // indx+1 coz each no has to be used once in the combination
    ans.pop_back();

    // remove duplicates
    while (idx + 1 < n && nums[idx] == nums[idx + 1])
        idx++;

    // not take
    subset(nums, ans, fans, idx + 1, n, target);
}

vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> ans;
    vector<vector<int>> fans;
    subset(nums, ans, fans, 0, n, target);
    return fans;
}
};