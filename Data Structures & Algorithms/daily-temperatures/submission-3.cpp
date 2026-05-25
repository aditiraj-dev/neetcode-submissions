class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> st;
        for(int i = temperatures.size() - 1; i >= 0; i--)
        {
            if(st.empty()) st.push(i);
            else
            {
                if(temperatures[i] < temperatures[st.top()]) {
                    res[i] = st.top() - i;
                    st.push(i);
                }
                else
                {
                    while(!st.empty() && temperatures[i] >= temperatures[st.top()]) st.pop();
                    if(!st.empty()) res[i] = st.top() - i;
                    st.push(i);
                }
            }
        }

        return res;
    }
};
