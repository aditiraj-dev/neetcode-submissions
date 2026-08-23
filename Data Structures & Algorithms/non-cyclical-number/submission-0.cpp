class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        int x = digitSq(n);
        while(x != 1)
        {
            x = digitSq(x);
            if(seen.count(x)) return false;
            seen.insert(x);
        }

        return x == 1;
    }

    int digitSq(int num)
    {
        int res = 0;
        while(num)
        {
            int digit = num % 10;
            res += digit*digit;
            num = num/10;
        }

        return res;
    }
};