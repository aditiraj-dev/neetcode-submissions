class DSU {
public:
    vector<int> Parent, Size;

    DSU(int n) : Parent(n + 1), Size(n + 1, 1) {
        for(int i = 0; i <= n; i++) Parent[i] = i;
    }

    int find(int node)
    {
        if(Parent[node] != node) Parent[node] = find(Parent[node]);
        return Parent[node];
    }

    bool unionSets(int u, int v)
    {
        int pu = find(u), pv =  find(v);
        if(pu == pv) return false;
        if(Size[pu] < Size[pv]) swap(pu, pv);
        Size[pu] += Size[pv];
        Parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //to find mst, use kruskals or prims
        int n = points.size();
        DSU dsu(n);
        vector<array<int, 3>> edges;

        for(int i = 0; i < n; i++) //form edges between all points and record their weight
        {
            for(int j = i + 1; j < n; j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i , j}); //each pair of vertice: weight, u, v
            }
        }

        sort(edges.begin(), edges.end()); //sort the edges to go from least smallest edge 
        int res = 0;
        for(auto& [dist, u, v] : edges)
        {
            if(dsu.unionSets(u, v)) res += dist;
        }

        return res;
    }
};
