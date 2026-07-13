class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> cars;

        for(int i = 0; i < speed.size(); i++)
        {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end());
        
        stack<double> st;
        for(int i = cars.size() - 1; i >= 0; i--)
        {
            double time = (target - cars[i][0]) / (double)cars[i][1];
            if(st.empty()) st.push(time);
            else if(st.top() < time) st.push(time);
        }

        if(st.empty()) return -1;
        return st.size();
    }
};
