class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int one = 0;
        int two = 0;
        for(int i = cost.size() - 1; i >=0; i--)
        {
            int temp1 = one;
            one = min(cost[i] + temp1, cost[i] + two);
            two = temp1;
        }
        return min(one, two);
    }
};
