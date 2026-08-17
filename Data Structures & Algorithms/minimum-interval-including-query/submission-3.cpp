class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<int> qry = queries;
        sort(qry.begin(), qry.end());
        map<int, int> res;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        int i = 0;
        for(int q : qry)
        {
            while(i < intervals.size() && intervals[i][0] <= q)
            {
                minHeap.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }

            while(!minHeap.empty() && minHeap.top().second < q)
            {
                minHeap.pop();
            }

            res[q] = minHeap.empty()? -1 : minHeap.top().first;
        }

        vector<int> result(queries.size());
        for(int j = 0; j < queries.size(); j++)
        {
            result[j] = res[queries[j]];
        }

        return result;
    }
};
