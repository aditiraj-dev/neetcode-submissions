class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> s1(26, 0);
        vector<int> s2(26, 0);

        for(int i = 0; i<s.size(); i++)
        {
            s1[s[i] - 'a']++;
            s2[t[i] - 'a']++;
        }

        return s1 == s2;
    }
};
