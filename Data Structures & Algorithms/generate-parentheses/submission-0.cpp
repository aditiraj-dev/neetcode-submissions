class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string b = "";
        int oB = n;
        int cB = n;
        backtrack(b, oB, cB);
        return res;
    }

    void backtrack(string b, int oB, int cB)
    {
        if(oB == 0 && cB == 0)
        {
            res.push_back(b);
            return;
        }

        if(oB > 0) {
            backtrack(b + "(", oB - 1, cB);
        }
        
        if(cB > 0 && cB > oB) {
            backtrack(b + ")", oB, cB - 1);
        }
    }
};
