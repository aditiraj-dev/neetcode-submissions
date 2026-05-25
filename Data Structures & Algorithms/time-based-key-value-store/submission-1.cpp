class TimeMap {
public:
    TimeMap() {
        
    }

    unordered_map<string, vector<pair<int, string>>> m;
    
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = m[key].size() - 1;
        string res = "";
        
        while(l <= r)
        {
            int mid = (l + r)/2;
            if(m[key][mid].first <= timestamp) {
                res = m[key][mid].second;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        return res;
    }
};
