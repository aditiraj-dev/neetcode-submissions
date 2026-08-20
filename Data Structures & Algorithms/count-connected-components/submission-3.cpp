class Solution {
public:
    unordered_map<int, vector<int>> graph;
    int countComponents(int n, vector<vector<int>>& edges) {
        for(auto e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        unordered_set<int> visited;
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(visited.count(i)) continue;
            res++;
            dfs(i, visited);
        }

        return res;
    }

    void dfs(int i, unordered_set<int>& visited)
    {
        if(visited.count(i)) return;
        visited.insert(i);

        for(int n : graph[i])
        {
            dfs(n, visited);
        }
    }
};
