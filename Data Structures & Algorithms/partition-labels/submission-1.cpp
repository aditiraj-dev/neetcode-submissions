class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> intervals;

        unordered_map<char, vector<int>> subs;

        for(int i = 0; i < s.size(); i++)
        {
            if(subs.count(s[i]))
                subs[s[i]][1] = i;
            else
                subs[s[i]] = {i, i};
        }

        for(auto& sub : subs)
        {
            intervals.push_back(sub.second);
        }

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(auto& interval : intervals)
        {
            int start = interval[0];
            int end = interval[1];
            int lastEnd = res.back()[1];

            if(start <= lastEnd)
            {
                res.back()[1] = max(lastEnd, end);
            }
            else
            {
                res.push_back({start, end});
            }
        }

        vector<int> result;

        for(auto& interval : res)
        {
            result.push_back(interval[1] - interval[0] + 1);
        }

        return result;
    }
};