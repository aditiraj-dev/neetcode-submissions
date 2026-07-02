class Solution {
public:
    vector<int> memo;
    int numDecodings(string s) {
        memo.resize(s.size(), -1);
        //we need to find number of ways to decode a string
        //obviously we would need to go digit by digit
        //at each digit we have a choice, we can decode it as a single character (unless 0) an move on to rest of string
        //otherwise take 2 digits at a time
        //this means to we need explore a number of ways to decode the string, a number of combinations formed by different decisions at each digit
        //this can be done recursively, and that will be the brute force approach
        return helper(s, 0);
    }

    int helper(string s, int i)
    {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(memo[i] != -1) return memo[i];

        memo[i] = helper(s, i + 1); 

        if(i + 1 < s.size() && ((s[i] == '1') || (s[i] == '2' && s[i+1] < '7')))
            memo[i] += helper(s, i + 2);

        return memo[i];
    }
};
