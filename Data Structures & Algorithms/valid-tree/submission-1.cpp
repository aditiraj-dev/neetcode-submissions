class Solution {
public:
    vector<vector<int>> adj;
    bool validTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto& e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_set<int> visit;
        if(!dfs(0, -1, visit)) return false;

        return visit.size() == n;
    }

    bool dfs(int node, int parent, unordered_set<int>& visit)
    {
        if(visit.count(node)) return false;

        visit.insert(node);
        for(int nei : adj[node])
        {
            if(nei == parent) continue;

            if(!dfs(nei, node, visit)) return false;
        }

        return true;
    }
};
