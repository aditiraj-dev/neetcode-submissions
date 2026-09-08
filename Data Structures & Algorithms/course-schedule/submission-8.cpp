class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       //if cycle, cannot finish
       unordered_map<int, vector<int>> edges; //adjacency list
       for(auto& pre : prerequisites) {
        edges[pre[1]].push_back(pre[0]);
       } 

       for(int i = 0; i < numCourses; i++)
       {
        unordered_set<int> visited;
        if(!dfs(i, edges, visited)) 
        {
            cout << i;
            return false;
        }
       }

       return true;
    }

    bool dfs(int node, unordered_map<int, vector<int>>& edges, unordered_set<int>& visited) //returns true if dfs possible otherwise false for loops
    {
        if(visited.count(node)) return false;
        visited.insert(node);

        for(int nei : edges[node])
        {
            if(!dfs(nei, edges, visited)) return false;
        }
        visited.erase(node);
        edges[node].clear();
        return true;
    }
};
