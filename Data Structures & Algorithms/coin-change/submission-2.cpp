class Solution {
public:
    unordered_map<int, int> memo;
    int coinChange(vector<int>& coins, int amount) {
        int res = helper(coins, amount);

        return res >= 1e9 ? -1 : res;
    }

    int helper(vector<int>& coins, int amount)
    {
        if(amount == 0) return 0;
        if(memo.find(amount) != memo.end()) return memo[amount];

        int res = 1e9;

        for(int coin : coins)
        {
            if(coin <= amount) 
            {
                res = min(res, 1 + helper(coins, amount - coin));
            }
        }

        memo[amount] = res;
        return res;
    }
};
