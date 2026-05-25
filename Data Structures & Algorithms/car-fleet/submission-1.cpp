class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for(int i = 0; i < speed.size(); i++)
        {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());

        vector<double> st;

        for(auto& p : cars)
        {
            st.push_back((double)(target - p.first)/p.second);
            if(st.size() >= 2 && st.back() <= st[st.size() - 2])
            {
                st.pop_back();
            }
        }

        return st.size();
    }
};
