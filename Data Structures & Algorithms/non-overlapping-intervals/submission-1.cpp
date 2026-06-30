class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //find the maximum no of non overlapping intervals
        sort(intervals.begin(), intervals.end());
        return intervals.size() - helper(intervals, 0, -1);
    }

    int helper(vector<vector<int>>& intervals, int i, int j)
    {
        if(i == intervals.size()) return 0;

        int res = helper(intervals, i + 1, j);
        if(j == -1 || intervals[j][1] <= intervals[i][0])
        {
            res = max(res, 1 + helper(intervals, i + 1, i));
        }

        return res;
    }
};
