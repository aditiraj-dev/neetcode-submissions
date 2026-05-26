class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freqT;
        unordered_map<char, int> window;

        for(char c : t) freqT[c]++;

        int l = 0;
        int need = freqT.size(), have = 0;
        int resLen = INT_MAX;
        pair<int, int> res = {-1, -1};

        for(int r = 0; r < s.size(); r++)
        {
            window[s[r]]++;

            if(freqT.count(s[r]) && window[s[r]] == freqT[s[r]]) have++;

            while(have == need)
            {
                if(r - l + 1 < resLen)
                {
                    resLen = r- l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if(freqT.count(s[l]) && window[s[l]] < freqT[s[l]]) have--;

                l++;
            }
        }

        return resLen == INT_MAX? "" : s.substr(res.first, resLen);

        //iterate through s with a dynamic sliding window
        //update what you have
        //extend window till what you have is greater or equal to need then update res
        //shrink window till you reach min where have >= need to make it as small as possible

    }
};
