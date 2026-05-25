class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        //s2 contains a permutation of s1 if there is a substring in s2 with the same hashmap as s1
        //so window size is s1's size
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        int w = s1.size();

        for(int i = 0; i < w; i++)
        {
            freq1[s1[i] - 'a']++; 
            freq2[s2[i] - 'a']++;
        }

        if(freq1 == freq2) return true;

        for(int l = 1; l <= s2.size() - w; l++) //iterating through all substrings
        {
            freq2[s2[l - 1] - 'a']--;
            freq2[s2[l + w - 1] - 'a']++;

            if(freq1 == freq2) return true;
        }

        return false;
    }
};
