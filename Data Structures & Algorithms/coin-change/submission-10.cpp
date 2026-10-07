class Solution {
public:
    unordered_map<int, int> m;
    int coinChange(vector<int>& coins, int amount) {
        int res = helper(coins, amount);
        return res == 1e9? -1 : res;
    }

    int helper(vector<int>& coins, int amount) //returns mininum number of coins needs to make amount
    {
        if(amount == 0) return 0;
        if(m.count(amount)) return m[amount];
        int res = 1e9;
        for(int c : coins)
        {
            if(c <= amount) res = min(res, 1 + helper(coins, amount - c));
        }

        return m[amount] = res;
    }
};
