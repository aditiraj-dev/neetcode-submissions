class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1);
        dp[0] = 0;
        
        for(int a = 1; a <= amount; a++)
        {
            int res = 1e9;
            for(int c : coins)
            {
                if(c <= a) res = min(res, 1 + dp[a - c]);
                dp[a] = res;
            }
        }

        return dp[amount] == 1e9? -1: dp[amount];
    }
};
