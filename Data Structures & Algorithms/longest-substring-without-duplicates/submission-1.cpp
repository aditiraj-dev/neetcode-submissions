class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;
        unordered_set<char> ch;
        
        for(int r = 0; r < s.length(); r++)
        {
            while(ch.find(s[r]) != ch.end())
            {
                ch.erase(s[l]);
                l++;
            }
            ch.insert(s[r]);
            res = max(res, r - l + 1);
        }

        return res;
    }
};
