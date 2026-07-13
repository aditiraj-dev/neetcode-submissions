class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_set<char> w;
        int res = 0;

        for(int r = 0; r < s.size(); r++)
        {
            while(w.count(s[r]))
            {
                w.erase(s[l]);
                l++;
            }
            w.insert(s[r]);
            res = max(res, r - l + 1);
        }

        return res;
    }
};
