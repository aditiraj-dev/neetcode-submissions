class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        char top = ' ';

        for(int i = 0; i<s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push_back(s[i]);

            if(!st.empty()) top = st.back();
            else top = ' ';

            if(s[i] == ')')
            {
                if(top == '(') st.pop_back();
                else return false;
            }
            if(s[i] == ']')
            {
                if(top == '[') st.pop_back();
                else return false;
            }
            if(s[i] == '}')
            {
                if(top == '{') st.pop_back();
                else return false;
            }
            
        }

        return st.empty();
    }
};
