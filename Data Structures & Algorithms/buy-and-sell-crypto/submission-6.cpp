class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minB = prices[0];
        int profit = 0;

        for(int s : prices)
        {
            profit = max(profit, s - minB);
            minB = min(s, minB);
        }

        return profit;
    }
};
