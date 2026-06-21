class Solution {
public:
    unordered_map<int, bool> memo;  
    bool wordBreak(string s, vector<string>& wordDict) { 
        memo[s.length()] = true;
        return helper(s, wordDict, 0);
    }

    bool helper(string s, vector<string>& wordDict, int i)
    {
        if(memo.count(i)) return memo[i];

        for(string w : wordDict)
        {
            if(i + w.length() <= s.length())
            {
                if(s.substr(i, w.length()) == w)
                {
                    if(helper(s, wordDict, i + w.length()))
                    {
                        memo[i] = true;
                        return true;
                    }
                }
            }
        }

        memo[i] = false;

        return false;
    }
};
