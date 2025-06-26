class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {

        // ttabulation 
        int n = coins.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n, vector<int>(amount + 1, INF));

        // Base case: amt = 0 → 0 coins needed
        for (int i = 0; i < n; i++) dp[i][0] = 0;

        // Base case for first coin only
        for (int amt = 1; amt <= amount; amt++) {
            if (amt % coins[0] == 0)
                dp[0][amt] = amt / coins[0];
        }

        // Fill the table
        for (int i = 1; i < n; i++) {
            for (int amt = 1; amt <= amount; amt++) {
                int notTake = dp[i - 1][amt];
                int take = INF;
                if (coins[i] <= amt)
                    take = 1 + dp[i][amt - coins[i]];

                dp[i][amt] = min(take, notTake);
            }
        }

        int ans = dp[n - 1][amount];
        return (ans >= INF) ? -1 : ans;
    }
};
