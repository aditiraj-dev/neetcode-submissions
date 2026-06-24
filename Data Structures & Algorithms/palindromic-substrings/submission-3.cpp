class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(isPalindrome(s.substr(i, j - i + 1))) res++;
            }
        }

        return res;
    }

    bool isPalindrome(string str)
    {
        int l = 0, r = str.size() - 1;
        while(l < r)
        {
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
