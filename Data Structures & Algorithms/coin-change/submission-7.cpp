class Solution {
public:
    vector<int> memo;
    int coinChange(vector<int>& coins, int amount) {
        //constraint: less than 20, gives backtracking or recursion
        //op is minimum 'ways' -> optimize brute using dp
        memo.resize(amount + 1, -1);
        int minCoins = helper(coins, amount); //gives the fewest number of coins to make amt
        return minCoins == 1e9? -1 : minCoins;
    }

    int helper(vector<int>& coins, int amount)
    {
        if(amount == 0) return 0;
        if(memo[amount] != -1) return memo[amount];
        int res = 1e9;
        for(int c : coins)
        {
            if(c <= amount)
            {
                res = min(res, 1 + helper(coins, amount - c));
            }
        }

        memo[amount] = res;
        return memo[amount];
    }
};
