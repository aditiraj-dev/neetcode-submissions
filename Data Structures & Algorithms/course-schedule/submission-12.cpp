class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //to check if is cycle exists in graph
        unordered_map<int, vector<int>> adj; //adjacency list
        for(auto p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }

        //some nodes might be isolated or graph might be disjoint, so run dfs starting from all nodes
        for(int i = 0; i < numCourses; i++)
        {
            unordered_set<int> v;
            if(dfs(i, adj, v))
            {
                cout << i;
                return false;
            }
        }

        return true;
    }

    bool dfs(int i, unordered_map<int, vector<int>>& adj, unordered_set<int>& v) //checks if cycle exists
    {
        if(v.count(i)) return true;
        v.insert(i);
        for(int nei : adj[i])
        {
            if(dfs(nei, adj, v)) return true;
        }
        v.erase(i);
        adj[i].clear();
        return false;
    }
};
