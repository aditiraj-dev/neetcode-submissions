class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string s = "";
        //int open = n, close = n;
        backtrack(n, n, s);
        return res;
    }

    void backtrack(int open, int close, string& s)
    {
        if(open == 0 && close == 0)
        {
            res.push_back(s);
            return;
        }

        if(open)
        {
            s += "(";
            open--;
            backtrack(open, close, s);
            s.pop_back();
            open++;
        }

        if(close && open < close)
        {
            s += ")";
            close--;
            backtrack(open, close, s);
            s.pop_back();
            close++;
        }
    }
};
