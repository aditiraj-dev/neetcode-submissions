class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res = 0;
        int prevEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(prevEnd > intervals[i][0]) //overlapping, choose the interval that ends earlier
            {
                prevEnd = min(prevEnd, intervals[i][1]);
                res++;
            }
            else prevEnd = intervals[i][1];
        }

        return res;

    }
};
