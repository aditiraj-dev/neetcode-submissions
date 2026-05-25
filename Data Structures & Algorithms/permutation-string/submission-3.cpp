class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> f1(26, 0);

        for(char c : s1)
        {
            f1[c - 'a']++;
        }

        int valid;

        for(int i = 0; i <= s2.size() - s1.size(); i++)
        {
            vector<int> f2(26, 0);
            for(int j = i; j < i + s1.size(); j++)
            {
                f2[s2[j] - 'a']++;
            }
            int valid = 1;
            for(char c : s1)
            {
                if(f1[c - 'a'] != f2[c - 'a']) valid = false;
            }

            if(valid) return true;
        }

        return false;
    }
};
