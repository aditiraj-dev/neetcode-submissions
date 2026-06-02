class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache(cost.size(), -1);
        return min(dfs(0, cache, cost), dfs(1, cache, cost));
    }

    int dfs(int i, vector<int>& cache, vector<int>& cost)
    {
        if(i>= cost.size()) return 0;

        if(cache[i] != -1) return cache[i];

        cache[i] = cost[i] + min(dfs(i+1, cache, cost), dfs(i+2, cache, cost));

        return cache[i];
    }
};
