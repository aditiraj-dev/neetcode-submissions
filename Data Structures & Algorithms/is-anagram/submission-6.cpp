class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        vector<char> f1(26, 0);
        vector<char> f2(26, 0);

        for(int i = 0; i < s.length(); i++)
        {
            f1[s[i] - 'a']++;
            f2[t[i] - 'a']++;
        }

        return f1 == f2;
    }
};
