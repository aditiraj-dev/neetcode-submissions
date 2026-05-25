class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string s : strs)
        {
            res += to_string(s.length()) + '#' + s;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size())
        {    
            string length;
            while(s[i] != '#')
            {
                length += s[i];
                i++;
            }

            string word = s.substr(i + 1, stoi(length));
            res.push_back(word);
            i = i + stoi(length) + 1;
        }

        return res;
    }
};
