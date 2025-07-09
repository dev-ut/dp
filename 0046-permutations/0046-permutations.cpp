class Solution {
public:
void permutation(vector<int>& nums, vector<vector<int>>& fans, vector<int>& ans, vector<bool>& used, int indx) {
    if (ans.size() == nums.size()) 
    {
        fans.push_back(ans);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) 
    {
        if (!used[i]) 
        {
            ans.push_back(nums[i]);
            used[i] = true;
            permutation(nums, fans, ans, used, i + 1);
            
            ans.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> fans;
    vector<int> ans;
    vector<bool> used(nums.size(), false);
    permutation(nums, fans, ans, used, 0);
    return fans;
}
};