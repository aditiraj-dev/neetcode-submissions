class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        return intervals.size() - helper(intervals, 0, -1);
    }

    int helper(vector<vector<int>>& intervals, int i, int prevEnd) //helper returns maximum no of intervals that can be kept without overlap
    {
        if(i == intervals.size()) return 0;
        int res = 0;
        if(prevEnd == -1 || intervals[i][0] >= prevEnd) res += 1 + helper(intervals, i + 1, intervals[i][1]); //take this interval

        res = max(res, helper(intervals, i + 1, prevEnd)); //skip this interval
        return res;
    }
};
