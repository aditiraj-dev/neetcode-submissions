class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);

        for(int i = temperatures.size() - 1; i >=0; i--)
        {
            if(st.empty())
            {
                //res[i] = 0;
                st.push(i);
            }
            else if(temperatures[i] < temperatures[st.top()])
            {
                res[i] = st.top() - i;
                st.push(i);
            }
            else if(temperatures[i] >= temperatures[st.top()])
            {
                while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                {
                    st.pop();
                }
                if(!st.empty()) res[i] = st.top() - i;
                st.push(i);
            }
        }

        return res;
    }
};
