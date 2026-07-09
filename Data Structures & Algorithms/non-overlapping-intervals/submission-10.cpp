class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //min no of intervals to remove for remaining to be overlapping
        //hence total minus max that can overlap
        sort(intervals.begin(), intervals.end());
        return intervals.size() - helper(intervals, 0, -1);
    }

    int helper(vector<vector<int>>& intervals, int i, int prev) //helper returns max no of overlapping intervals from i till end given interval at prev last chosen
    {
        if(i == intervals.size()) return 0;

        int res = 0;
        if(prev == -1 || intervals[prev][1] <= intervals[i][0]) res = 1 + helper(intervals, i+1, i); //choose this interval if not overlapping
        res = max(res, helper(intervals, i + 1, prev));
        return res;
    }
};
