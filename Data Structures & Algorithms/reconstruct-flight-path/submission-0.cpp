class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //source node is always jfk
        //keep going to the next vertex
        //if all visited, stop
        //otherwise keep going, visit vertices again if needed
        unordered_map<string, vector<string>> adj;
        sort(tickets.begin(), tickets.end());
        for(auto& ticket : tickets)
        {
            adj[ticket[0]].push_back(ticket[1]);
        }
        vector<string> res = {"JFK"};
        dfs("JFK", res, adj, tickets.size() + 1);
        return res;
    }

    bool dfs(string src, vector<string>& res, unordered_map<string, vector<string>>& adj, int targetLen)
    {
        if(res.size() == targetLen) return true; //stop when all tickets are used
        if(adj.find(src) == adj.end()) return false;
        vector<string> temp = adj[src]; //neighbors
        for(int i = 0; i < temp.size(); i++)
        {
            string v = temp[i];
            adj[src].erase(adj[src].begin() + i); //ticket used, so remove it
            res.push_back(v);
            if(dfs(v, res, adj, targetLen)) return true; //lead to a complete itinerary, keep it
            adj[src].insert(adj[src].begin() + i, v); //otherwise backtrack and restore ticket to explore other possibilities?
            res.pop_back();
        }

        return false;
    }
};
