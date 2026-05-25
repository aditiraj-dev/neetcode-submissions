class Solution {
public:
    bool isValid(string s) {
       stack<char> st;

       for(char c : s)
       {
            if(c == '[' || c =='{' || c == '(') st.push(c);
            else
            {
                char top = st.empty() ? ' ' : st.top();

                if(c == ']' && top == '[') st.pop();
                else if(c == ')' && top == '(') st.pop();
                else if(c == '}' && top == '{') st.pop();
                else return false;
            }
       }

       if(st.empty()) return true;
       return false;
    }
};
