class Solution {
public:
    unordered_map<int, vector<int>> graph;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //basically must check if graph has cycles
        for(vector<int> x : prerequisites)
        {
            graph[x[1]].push_back(x[0]); //b course to a course
        }

        for(int i = 0; i < numCourses; i++)
        {
            if(!graph.count(i)) continue;
            unordered_set<int> visited;
            if(dfs(i, visited)) return false;
        }

        return true;
    }

    bool dfs(int n, unordered_set<int>& visited) //checks if cycle present
    {
        if(visited.count(n)) return true;
        if(graph[n].empty()) return false;
        visited.insert(n);

        for(int nei : graph[n])
        {
            if(dfs(nei, visited)) return true;
        }

        visited.erase(n);
        graph[n].clear();
        return false;
    }
};
