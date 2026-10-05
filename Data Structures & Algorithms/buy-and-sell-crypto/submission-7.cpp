class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return helper(prices, 0, 0);
    }

    int helper(vector<int>& prices, int i, int state) //returns max profit possible from i till end
    {
        if(i == prices.size()) return 0;
        //at every i, you have two choices: to buy or sell
        //if already holding a stock, can only sell it for next stocks (at a higher price)
        //if not holding, can only buy or skip
        int res = 0;
        if(state == 0) res = max(-prices[i] + helper(prices, i + 1, 1), helper(prices, i + 1, 0));
        else if(state == 1)
        {
            //either sell or skip
            res = max(prices[i] + helper(prices, i + 1, 2), helper(prices, i + 1, 1));
        }

        return res;
    }
};
