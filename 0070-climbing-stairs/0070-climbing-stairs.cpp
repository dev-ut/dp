class Solution {
public:
    int solve(int indx, int n, vector<int>& memo) 
    {
        if (indx == n) return 1;        // 1 valid path
        if (indx > n) return 0;         // no valid path

        if (memo[indx] != -1) return memo[indx];

        // memoize the number of ways from current index
        return memo[indx] = solve(indx + 1, n, memo) + solve(indx + 2, n, memo);
    }

    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return solve(0, n, memo);
    }
};


