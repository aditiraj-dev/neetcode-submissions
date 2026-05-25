class Solution {
public:

    string encode(vector<string>& strs) {
        string s ="";

        for(int i = 0; i < strs.size(); i++)
        {
            s += to_string(strs[i].length()) + '#' + strs[i];
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;

        //you keep going and count the length until you encounter hash 
        //extract the string after hash of this length

        for(int i = 0; i < s.length();)
        {
            string lengthStr = "";
            int j = i;
            while(s[j] != '#')
            {
                lengthStr += s[j];
                j++;
            }

            int len = stoi(lengthStr);
            string str = s.substr(j + 1, len);
            res.push_back(str);

            i = j + 1 + len; 
        }

        return res;
    }
};
