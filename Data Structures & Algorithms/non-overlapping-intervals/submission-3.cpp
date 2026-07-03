class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res = 0;
        int last = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] < last)
            {
                res++;
                last = min(last, intervals[i][1]); //we keep the interval that ends first, because the interval that is longer will have more chances of overlap 
            }
            else
            {
                last = intervals[i][1];
            }
        }
        return res;
    }
};
