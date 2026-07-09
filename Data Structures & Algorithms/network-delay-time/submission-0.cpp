class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for(const auto& time : times) edges[time[0]].emplace_back(time[1], time[2]);
        //edges maps one vertex to adjacent vertices with the distance: u -> v, d

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        //minHeap orders by distance, so: d -> v

        minHeap.push({0, k});

        set<int> visited;
        int t = 0;

        while(!minHeap.empty())
        {
            auto curr = minHeap.top();
            minHeap.pop();
            int t1 = curr.first, u = curr.second;
            if(visited.count(u)) continue;
            visited.insert(u);
            t = t1;

            if(edges.count(u))
            {
                for(const auto& adj : edges[u]) 
                {
                    int v = adj.first, t2 = adj.second;
                    if(!visited.count(v)) minHeap.push({t1 + t2, v});
                }
            }
        }

        return visited.size() == n ? t : -1;
    }
};
