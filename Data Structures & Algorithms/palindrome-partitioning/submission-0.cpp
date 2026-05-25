class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> part;
        backtrack(0, s, part);
        return res;
    }

    void backtrack(int i, const string& s, vector<string>& part)
    {
        if(i >= s.length())
        {
            res.push_back(part);
            return;
        }

        for(int j = i; j < s.length(); j++)
        {
            if(isPalin(i, j, s))
            {
                part.push_back(s.substr(i, j - i + 1));
                backtrack(j + 1, s, part);
                part.pop_back();
            }
        }
    }

    bool isPalin(int i, int j, const string& s)
    {
        while(i < j)
        {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};
