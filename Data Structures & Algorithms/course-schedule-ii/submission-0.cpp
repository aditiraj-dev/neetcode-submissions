class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (auto& pre : prerequisites) {
            indegree[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res(numCourses, 0);

        int finish = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res[numCourses - finish - 1] = node;
            finish++;
            for(int nei : adj[node])
            {
                indegree[nei]--;
                if(indegree[nei] == 0) q.push(nei);
            }
        }

        if(finish == numCourses) return res;
        return {};
    }
};
