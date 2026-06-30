class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> last = intervals[0];

        for(auto& interval : intervals)
        {
            if(interval == last) continue;
            if(interval[0] <= last[1])
            {
                last[1] = max(interval[1], last[1]);
            }
            else
            {
                res.push_back(last);
                last = interval;
            }
        }
        res.push_back(last);
        return res;
    }
};
