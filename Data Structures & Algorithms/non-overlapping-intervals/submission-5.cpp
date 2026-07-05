class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(prevEnd > intervals[i][0]) //overlapping, greedily remove the interval that ends last by updating prevEnd
            {
                prevEnd = min(intervals[i][1], prevEnd);
                res++;
            }
            else
            {
                prevEnd = intervals[i][1];
            }
        }

        return res;
    }
};
