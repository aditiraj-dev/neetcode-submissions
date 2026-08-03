class Solution {
public:
    vector<vector<int>> adj;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        adj.resize(edges.size() + 1);
        for(auto& e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);

            unordered_set<int> visited;
            if(dfs(e[0], -1, visited)) return {e[0], e[1]};
        }

        return {};
        
    }

    bool dfs(int node, int parent, unordered_set<int>& visited)
    {
        if(visited.count(node)) return true;

        visited.insert(node);
        for(int nei : adj[node])
        {
            if(nei == parent) continue;
            if(dfs(nei, node, visited)) return true;
        }

        return false;
    }
};
