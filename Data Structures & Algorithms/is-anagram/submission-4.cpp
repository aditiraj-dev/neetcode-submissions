class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<int, int> s1;
        unordered_map<int, int> s2;

        for(int i = 0; i<s.size(); i++)
        {
            s1[s[i] - 'a']++;
            s2[t[i] - 'a']++;
        }

        return s1 == s2;
    }
};
