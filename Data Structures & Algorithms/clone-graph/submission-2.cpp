/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> clones;
    Node* cloneGraph(Node* node) {
        //we need to clone a graph, to return a deep copy
        //so we need to clone each node by creating a separate node for it
        //to clone all nodes, we need to run dfs on the graph
        //avoid cycles by using a visited set
        return helper(node); //creates a deep copy of node: which involves setting up val and neighbors of node
    }

    Node* helper(Node* node)
    {
        if(node == nullptr) return nullptr;
        if(clones.count(node)) return clones[node];
                                     
        Node* c = new Node(node->val);
        clones[node] = c;
        for(Node* n : node->neighbors)
        {
            c->neighbors.push_back(helper(n));
        }

        return clones[node];
    }
};
