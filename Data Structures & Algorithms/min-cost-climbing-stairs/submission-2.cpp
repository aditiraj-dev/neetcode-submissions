class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //we need to find minimum cost to reach the top of the staircase
        vector<int> dp(cost.size() + 1); //minimum cost to reach step i
        dp[0] = 0;
        dp[1] = 0;

        for(int i = 2; i <= cost.size(); i++)
        {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }

        return dp[cost.size()];
    }
};
