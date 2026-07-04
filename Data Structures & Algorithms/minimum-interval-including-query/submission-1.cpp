class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<int> qry = queries;
        sort(qry.begin(), qry.end());
        
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);
        int i = 0;
        map<int,int> res;
        for(int q : qry)
        {   
            while(i < intervals.size() && intervals[i][0] <= q)
            {
                minHeap.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }

            while(!minHeap.empty() && minHeap.top()[1] < q) minHeap.pop();

            res[q] = minHeap.empty() ? -1: minHeap.top()[0];
        }

        vector<int> result(queries.size());
        for(int j = 0; j < queries.size(); j++) result[j] = res[queries[j]];

        return result;

    }
};
