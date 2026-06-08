class Solution {
public:
    int climbStairs(int n) {
        int zero = 1, one = 1;

        for(int i = 1; i < n; i++)
        {
            int temp = one;
            one = zero;
            zero = zero + temp;
        }

        return zero;
    }
};
