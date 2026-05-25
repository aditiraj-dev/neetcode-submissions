class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        string res;

        for(string s : strs)
        {
            res += to_string(s.length()) + '#' + s;
        }

        return res;
    }

    vector<string> decode(string s) {
        if(s.length() == 0) return {};
        vector<string> result;

        int i = 0;
        while(i < s.length())
        {
            string length;
            while(s[i] != '#')
            {
                length += s[i];
                i++;
            }
            //at this point i is at hash
            int len = stoi(length);
            //int j = i + 1;
            string word = s.substr(i+1, len);
            i = i + 1 + len;
            /*while(len)
            {
                word += s[j];
                j++;
                len--;
            } */
            result.push_back(word);
            //i = j;
        }

        return result;
    }
};
