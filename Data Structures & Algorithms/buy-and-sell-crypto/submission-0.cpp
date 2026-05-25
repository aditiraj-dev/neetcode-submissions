class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++)
        {
            for(int j = i + 1; j < prices.size(); j++)
            {
                int profit = 0;
                if(prices[j] > prices[i])
                {
                    profit = prices[j] - prices[i];
                }

                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};
