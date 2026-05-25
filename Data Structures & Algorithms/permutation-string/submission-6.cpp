class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        vector<int> f1(26, 0);
        vector<int> f2(26, 0);

        for(int i = 0; i < s1.length(); i++)
        {
            f1[s1[i] - 'a']++;
            f2[s2[i] - 'a']++;
        }

        int matches = 0;
        for(int i = 0; i < 26; i++)
        {
            if(f1[i] == f2[i]) matches++;
        }

        int l = 0;
        for(int r = s1.length(); r < s2.length(); r++)
        {
            if(matches == 26) return true;

            int index = s2[r] - 'a';
            f2[index]++;
            if(f1[index] == f2[index]) matches++;
            else if(f1[index] + 1 == f2[index]) matches--;

            index = s2[l] - 'a';
            f2[index]--;
            if(f1[index] == f2[index]) matches++;
            else if(f1[index] - 1 == f2[index]) matches--;

            l++;
        }

        return matches == 26;
    }
};
