class Solution {
public:
void solve(int k, int target, int curr, vector<int>& ans, vector<vector<int>>& fans)
{
    // base case
    if (target == 0 && ans.size() == k) 
    {
        fans.push_back(ans);
        return;
    }

    if (curr > 9 || target < 0 || ans.size() > k) return;

    // Take current number
    ans.push_back(curr);
    solve(k, target - curr, curr + 1, ans, fans);
    ans.pop_back(); // backtrack

    // Not take current number
    solve(k, target, curr + 1, ans, fans);
}

vector<vector<int>> combinationSum3(int k, int n) 
{
    vector<int> ans;
    vector<vector<int>> fans;
    solve(k, n, 1, ans, fans);
    return fans;
}
};
