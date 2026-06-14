class Solution {
public:
    string longestPalindrome(string s) {
        //we want to find the longest substring which is a palindrome
        int resIdx = 0, resLen = 0;

        for(int i = 0; i < s.size(); i++)
        {
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                if(r - l + 1 > resLen)
                {
                    resIdx = l;
                    resLen = r - l + 1;
                }

                l--;
                r++;
            }

            l = i, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                if(r - l + 1 > resLen)
                {
                    resIdx = l;
                    resLen = r - l + 1;
                }

                l--;
                r++;
            }
        }

        return s.substr(resIdx, resLen);
    }
};
