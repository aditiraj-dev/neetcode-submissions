class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string, vector<pair<int, string>>> m;
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& values = m[key];
        string res = "";

        int left = 0, right = values.size() - 1;

        while(left <= right)
        {
            int mid = (left + right)/ 2;
            if(values[mid].first <= timestamp) {
                res = values[mid].second;
                left = mid + 1;
            }
            else right = mid - 1;
        }

        return res;

    }
};
