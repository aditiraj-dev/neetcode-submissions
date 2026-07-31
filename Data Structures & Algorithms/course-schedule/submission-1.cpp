class Solution {
public:
    unordered_map<int, vector<int>> m;
    unordered_set<int> visiting;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //if topological order possible, then true
        //basically to detect cycles in graph

        for(const auto& p : prerequisites)
        {
            m[p[0]].push_back(p[1]);
        }

        for(int c = 0; c < numCourses; c++)
        {
            if(!dfs(c)) return false;
        }

        return true;
    }

    bool dfs(int c) //if no cycle, returns true
    {
        if(visiting.count(c)) return false;

        if(m[c].empty()) return true;

        visiting.insert(c);
        for(int p : m[c])
        {
            if(!dfs(p)) return false;
        }

        visiting.erase(c);
        m[c].clear();
        return true;
    }
};
