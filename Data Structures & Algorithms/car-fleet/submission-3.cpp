class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for(int i = 0; i < position.size(); i++)
        {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        stack<double> st;
        for(auto& pair : cars)
        {
            double t = (double)(target - pair.first)/(double)pair.second;

            if(st.empty()) st.push(t);
            else
            {
                if(t > st.top()) st.push(t);
            }
        }

        return st.size();
    }
};
