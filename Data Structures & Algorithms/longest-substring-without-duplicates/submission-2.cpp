class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //dynamic sliding window because longest substring

        int l = 0, r = 0;
        unordered_set<char> set;
        int maxL = 0;

        while(r < s.size())
        {
            while(set.find(s[r]) != set.end())
            {
                set.erase(s[l]);
                l++;
            }
            maxL = max(maxL, r - l + 1);
            set.insert(s[r]);
            r++;
        }

        return maxL;
    }
};
