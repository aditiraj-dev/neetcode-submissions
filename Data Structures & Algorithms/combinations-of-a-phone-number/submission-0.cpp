class Solution {
public:
    vector<string> res;
    unordered_map<int, string> m = {
            {2 , "abc"}, {3 , "def"}, {4 , "ghi"}, {5 , "jkl"}, {6 , "mno"}, {7 , "pqrs"}, {8 , "tuv"}, {9 , "wxyz"}
        };
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string s;
        backtrack(0, s, digits);
        return res;
    }

    void backtrack(int i, string& s, const string& digits)
    {
        if(i >= digits.length())
        {
            res.push_back(s);
            return;
        }

        for(char c : m[digits[i] - '0'])
        {
            s.push_back(c);
            backtrack(i + 1, s, digits);
            s.pop_back();
        }
    }
};
