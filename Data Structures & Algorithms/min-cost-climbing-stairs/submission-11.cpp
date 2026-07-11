class Solution {
public:
    vector<int> memo;
    int minCostClimbingStairs(vector<int>& cost) {
        memo.resize(cost.size(), -1);
        return min(helper(0, cost), helper(1, cost));
    }

    int helper(int i, vector<int>& cost) //returns minimum cost to reach top of staircase from i
    {
        if(i >= cost.size()) return 0; 
        if(memo[i] != -1) return memo[i];

        memo[i] = min(cost[i] + helper(i + 1, cost), cost[i] + helper(i + 2, cost));

        return memo[i];
    }
};
