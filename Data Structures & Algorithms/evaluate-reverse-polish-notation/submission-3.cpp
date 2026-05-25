class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(string s : tokens)
        {
            if(s != "+" && s != "-" && s != "*" && s != "/") st.push(s);
            else
            {
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                int res = 0;
                if(s == "+") res = a + b;
                else if(s == "-") res = b - a;
                else if(s == "*") res = a*b;
                else res = b/a;
                st.push(to_string(res));
            }
        }

        return stoi(st.top());
    }
};
