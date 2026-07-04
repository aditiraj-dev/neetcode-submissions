class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        //brute force approach would be to iterate through every query, and for that query iterate through each interval
        vector<int> res;
        for(int i= 0; i < queries.size(); i++)
        {
            int q = INT_MAX;
            for(int j = 0; j < intervals.size(); j++)
            {
                if(intervals[j][0] <= queries[i] && queries[i] <= intervals[j][1])
                {
                    int length = intervals[j][1] - intervals[j][0] + 1;
                    q = min(q, length);
                }
            }
            if(q == INT_MAX) q = -1;
            res.push_back(q);
        }

        return res;
    }
};
