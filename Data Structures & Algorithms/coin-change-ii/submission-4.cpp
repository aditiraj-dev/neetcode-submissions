class Solution {
public:
    vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        dp.resize(coins.size() + 1, vector<int>(amount + 1, -1));
        return helper(coins, 0, amount); //returns number of ways to make amount
    }

    int helper(vector<int>& coins, int i, int amount)
    {
        if(amount == 0) return 1; 
        if(i >= coins.size()) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];
        int res = 0;
        
        if(amount >= coins[i])
        {
            res = helper(coins, i + 1, amount) + helper(coins, i, amount - coins[i]);
        }

        dp[i][amount] = res;
        return res;
    }
};
