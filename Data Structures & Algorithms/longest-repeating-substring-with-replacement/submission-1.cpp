class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int l = 0;
        int maxF = 0;
        int maxL = 0;

        for(int r = 0; r < s.size(); r++)
        {
            count[s[r]]++;
            maxF = max(maxF, count[s[r]]);

            while((r - l + 1) - maxF > k)
            {
                count[s[l]]--;
                l++;
            }

            maxL = max(maxL, r - l + 1);
        }

        return maxL;
    }
};
