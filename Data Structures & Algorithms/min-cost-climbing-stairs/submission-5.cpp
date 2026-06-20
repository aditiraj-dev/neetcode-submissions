class Solution {
public:
    vector<int> memo;
    int minCostClimbingStairs(vector<int>& cost) {
        memo.resize(cost.size(), -1);
        return min(helper(cost, 0), helper(cost, 1));
    }

    int helper(vector<int>& cost, int i)
    {
        if(i >= cost.size()) return 0;
        if(memo[i] != -1) return memo[i];

        memo[i] = cost[i] + min(helper(cost, i + 1), helper(cost, i + 2));
        return memo[i];
    }
};
