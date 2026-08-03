class Solution {
public:
    vector<vector<int>> adj;
    int countComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto& e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        unordered_set<int> visited;
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(visited.count(i)) continue;
            res++;
            dfs(i, -1, visited);
        }

        return res;
    }

    void dfs(int n, int p, unordered_set<int>& visited)
    {
        if(visited.count(n)) return;
        visited.insert(n);
        for(auto& nei : adj[n])
        {
            //if(nei == p) continue;
            dfs(nei, n, visited);
        }
    }
};
