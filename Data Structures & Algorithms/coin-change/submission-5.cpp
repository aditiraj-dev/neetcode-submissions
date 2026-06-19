class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e9); //represents min coins to make amount
        dp[0] = 0; //base case
        //in recursive method, suppose for amount 10, we need to call 
        //function for 9, 8, 7,...

        for(int i = 1; i <= amount; i++) //so in bottom up, we start from i = 0
        {
            for(int coin :  coins)
            {
                if(coin <= i) dp[i] = min(dp[i], 1 + dp[i-coin]);
            }
        }

        return dp[amount] == 1e9? -1 : dp[amount];
    }
};
