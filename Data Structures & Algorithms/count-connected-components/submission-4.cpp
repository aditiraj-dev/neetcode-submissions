class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n)
    {
        parent.resize(n); //intially all nodes are their own sets
        rank.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int node)
    {
        int cur = node;
        while(cur != parent[cur])
        {
            parent[cur] = parent[parent[cur]];
            cur = parent[cur];
        }

        return cur;
    }

    bool unionSets(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return false; //in same set

        if(rank[pv] > rank[pu]) swap(pu, pv);

        parent[pv] = pu; //smaller set's parent is changed to the bigger one
        rank[pu] += rank[pv];
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //use union-find for connected regions
        DSU dsu(n);
        int res = n; //all nodes are different connected regions
        for(auto& e : edges)
        {
            if(dsu.unionSets(e[0], e[1])) res--; //if union was successfull (because they were in different sets) then decrement res
        }

        return res;
    }
};
