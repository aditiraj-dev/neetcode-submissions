class Solution {
public:
    vector<int> memo;
    int numDecodings(string s) {
        memo.resize(s.size(), -1);
        //to find number of ways a string can be decoded
        //we can find this recursively
        //because at each i, we have multiple valid choices, which all need to be counted to get the solution
        return helper(s, 0); //returns no of ways to decode a string from i till end
    }

    int helper(string s, int i)
    {
        if(i == s.size()) return 1; //reached end, decoding was successfull, so count this as one
        if(s[i] == '0') return 0;
        if(memo[i] != -1) return memo[i];

        //2 decisions here: decode one character, or 2

        int res = helper(s, i + 1); //decode just current character

        if(i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] < '7'))
        {
            res += helper(s, i + 2);
        }

        memo[i] = res;
        return res;
    }
};
