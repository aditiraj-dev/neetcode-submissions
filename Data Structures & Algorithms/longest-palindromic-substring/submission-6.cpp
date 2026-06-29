class Solution {
public:
    string longestPalindrome(string s) {
        //to return longest substring that is a palindrome
        //brute force: generate all substrings and check if they are palindromes
        //this can be optimized by dynamic programming because some strings do repeat
        //two pointers??
        int res = 0, resLen = -1;
        for(int i = 0; i < s.size(); i++)
        {
            int l = i, r = i;
            while(l >=0 && r < s.size() && s[l] == s[r])
            {
                if(r - l + 1 > resLen)
                {
                    resLen = r - l + 1;
                    res = l;
                }
                l--;
                r++;
            }
            l = i, r = i + 1;
            while(l >=0 && r < s.size() && s[l] == s[r])
            {
                if(r - l + 1 > resLen)
                {
                    resLen = r - l + 1;
                    res = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(res, resLen);
    }
};
