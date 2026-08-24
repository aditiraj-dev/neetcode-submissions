class Solution {
public:
    unordered_map<long long, double> memo;
    double myPow(double x, int n) {
        if(n > 0) return helper(x, n);
        long long N = -n;
        return helper(1/x, N);
    }

    double helper(double x, long long n)
    {
        if(n == 0.0 || x == 1.0) return 1.0;
        if(n == 1.0) return x;
        if(memo.count(n)) return memo[n];

        double r =  helper(x, n/2);
        if(n%2 == 0) return memo[n] = r*r;
        return memo[n] = r*helper(x, n - n/2);
    }
};
