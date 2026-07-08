class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<char, int>> s1;
        stack<pair<char, int>> s2;

        for(int i = 0; i< s.size(); i++)
        {
            if(s[i] == '(') s1.push({'(', i});
            if(s[i] == '*') s2.push({'*', i});
            if(s[i] == ')')
            {
                if(s1.empty() && s2.empty()) return false;
                else if(!s1.empty()) s1.pop();
                else s2.pop();
            }
        }

        while(!s1.empty())
        {
            if(s2.empty()) return false;
            else {
                if(s1.top().second > s2.top().second) return false;
                else
                {
                    s1.pop();
                    s2.pop();
                }
            }
        }

        return true;
    }
};
