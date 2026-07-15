class Solution {
public:
    int numDecodings(string s) {
        int one = 1, two = 0;

        for(int i = s.size() - 1; i >=0; i--)
        {
            int curr = 0;
            if(s[i] == '0')
            {
                two = one;
                one = curr;
                continue;
            }
            curr = one;
            if(i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] < '7'))
            {
                curr += two;
            }
            two = one;
            one = curr;
        }

        return one;
    }
};
