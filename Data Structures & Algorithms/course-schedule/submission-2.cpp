class Solution {
public:
    unordered_set<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> g;
        for(auto& pair : prerequisites)
        {
            g[pair[0]].push_back(pair[1]);
        }

        for(int c = 0; c < numCourses; c++)
        {
            if(!dfs(c, g)) return false;
        }

        return true;
    }

    bool dfs(int c, unordered_map<int, vector<int>>& g) //checks for cycles
    {
        if(visited.count(c)) return false;
        if(g[c].empty()) return true;

        visited.insert(c);
        for(int n : g[c])
        {
            if(!dfs(n, g)) return false;
        }
        visited.erase(c);
        g[c].clear();
        return true;    

    }
};
