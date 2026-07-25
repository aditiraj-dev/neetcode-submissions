class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);

        stack<pair<int,int>> st;

        for(int i = 0; i < temperatures.size(); i++)
        {
            if(st.empty() || st.top().first > temperatures[i]) st.push({temperatures[i], i});
            else
            {
                while(!st.empty() && st.top().first < temperatures[i])
                {
                    res[st.top().second] = i - st.top().second;
                    st.pop();
                    //st.push({temperatures[i], i});
                }
                st.push({temperatures[i], i});
            }
        }

        return res;
    }
};
