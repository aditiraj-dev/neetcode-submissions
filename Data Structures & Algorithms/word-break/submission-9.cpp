class Solution {
public:
    vector<int> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.resize(s.size(), -1);
        return helper(s, wordDict, 0); //checks if segmentation possible from start to end of s
    }

    bool helper(string s, vector<string>& wordDict, int i) //return if segmentation possible from i till end
    {
        if(i == s.size()) return true; //if we reach end of string, that means segmentation was successfully done
        if(memo[i] != -1) return memo[i];

        for(string w : wordDict) //from given dictionary, check if from current i we can form a word
        {
            if(i + w.length() <= s.size() && s.substr(i, w.length()) == w) //conditions if from current i we can form a word
            {
                if(helper(s, wordDict, i + w.length())) //formed a word, check the rest of the string. if this recursion call reaches end, then we can simply return true here
                {
                    memo[i] = true;
                    return true;
                }
            }
        }
        memo[i] = false;
        return false; //we can never reach end of the string from words in given dict, so return false
    }
};
