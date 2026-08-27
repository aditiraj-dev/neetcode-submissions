class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 1);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
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
        if(pv == pu) return false; //union cannot be done, belong to same tree
        if(rank[pv] > rank[pu]) swap(pu, pv);

        parent[pv] = pu;
        rank[pu] += rank[pv];
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n); //create a dsu to add all nodes to it, intialize parent vector and size of rank
        int res = n;
        for(auto& e : edges)
        {
            if(dsu.unionSets(e[0], e[1])) res--;
        }

        return res;
    }
};
