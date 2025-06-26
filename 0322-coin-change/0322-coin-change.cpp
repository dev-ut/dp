class Solution {
public:
    int solve(vector<int>& coins, int indx, int amount, vector<vector<int>>& dp) 
    {
        if (amount == 0) return 0;
        if (indx >= coins.size()) return 1e9;

        if (dp[indx][amount] != -1) return dp[indx][amount];

        int take = 1e9;
        if (coins[indx] <= amount) 
        {
            take = 1 + solve(coins, indx, amount - coins[indx], dp);
        }

        int notTake = solve(coins, indx + 1, amount, dp);

        return dp[indx][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(coins, 0, amount, dp);

        return (ans >= 1e9) ? -1 : ans;  // ✅ Use same constant
    }
};
