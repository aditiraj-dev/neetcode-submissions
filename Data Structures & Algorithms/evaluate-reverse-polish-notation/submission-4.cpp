class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(string t : tokens)
        {
            if(t != "+" && t != "-" && t != "/" && t != "*")
            {
                st.push(t);
            }
            else
            {
                int a = stoi(st.top());
                st.pop();

                int b = stoi(st.top());
                st.pop();

                int res = 0;
                if(t == "+") res = a + b;
                else if(t == "-") res = b - a;
                else if(t == "*") res = b*a;
                else res = b/a;

                st.push(to_string(res));
            }
        }

        return stoi(st.top());
    }
};
