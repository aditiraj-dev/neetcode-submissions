class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        for(int i = 0; i<s.length(); i++)
        {
            unordered_set<char> S;
            S.insert(s[i]);
            for(int j = i + 1; j<s.length(); j++)
            {
                if(S.find(s[j]) != S.end()) break;
                S.insert(s[j]);
            }

            res = max(res, (int)S.size());
        }

        return res;
    }
};
