class Solution {
public:
    vector<int> memo;
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 2);
        dp[cost.size()] = 0;
        dp[cost.size() + 1] = 0;

        for(int i = cost.size() - 1; i >= 0; i--)
        {
            dp[i] = min(cost[i] + dp[i+1], cost[i] + dp[i+2]);
        }

        return min(dp[0], dp[1]);
    }

    int dfs(vector<int>& cost, int i)
    {
        if(i >= cost.size()) return 0;
        if(memo[i] != -1) return memo[i];

        memo[i] = min(cost[i] + dfs(cost, i + 2), cost[i] + dfs(cost, i + 1));
        return memo[i];
    }
};
