class Solution {
public:
    unordered_map<string, int> dp;
    int maxProfit(vector<int>& prices) {
        return helper(prices, 0, false);
    }

    int helper(vector<int>& prices, int i, bool coin) //returns max profit that can be made from i till end
    {
        if(i >= prices.size()) return 0;
        //depending on coin, we can sell or buy, or skip
        string key = to_string(i) + '-' + to_string(coin);
        if(dp.count(key)) return dp[key];
        int cooldown = helper(prices, i + 1, coin);

        if(!coin)
        {
            int buy = helper(prices, i + 1, true) - prices[i];
            return dp[key] = max(buy, cooldown);
        }
        else
        {
            int sell = helper(prices, i + 2, false) + prices[i];
            return dp[key] = max(sell, cooldown);
        }
    }
};
