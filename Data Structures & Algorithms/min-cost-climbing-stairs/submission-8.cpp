class Solution {
public:
    vector<int> memo;
    int minCostClimbingStairs(vector<int>& cost) {
        memo.resize(cost.size(),-1);
        return min(dfs(cost, 0), dfs(cost, 1));
    }

    int dfs(vector<int>& cost, int i)
    {
        if(i >= cost.size()) return 0;
        if(memo[i] != -1) return memo[i];

        memo[i] = min(cost[i] + dfs(cost, i + 2), cost[i] + dfs(cost, i + 1));
        return memo[i];
    }
};
