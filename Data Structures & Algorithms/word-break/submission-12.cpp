class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1, false);
        dp[s.size()] = true;
        
        for(int i = s.size() - 1; i >=0; i--)
        {
            for(string w : wordDict)
            {
                if(i + w.length() <= s.size() && s.substr(i, w.length()) == w)
                {
                    if(dp[i + w.length()]) dp[i] = true;
                }
            }
        }

        return dp[0];
    }
    /*
    bool helper(string s, vector<string>& wordDict, int i) //returns if from current index till last we can form it using the given dict
    {
        if(i == s.size()) return true;
        if(memo[i] != -1) return memo[i];
        for(string w : wordDict)
        {
            if(i + w.length() <= s.size() && s.substr(i, w.length()) == w)
            {
                if(helper(s, wordDict, i + w.length()))
                {
                    memo[i] = true;
                    return true;
                }
            }
        }
        memo[i] = false;
        return false;
    }
    */
};
