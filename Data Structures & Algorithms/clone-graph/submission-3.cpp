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
        //we need to create a deep copy of the graph
        //this means we need to create a copy of each node in original graph and with the same edges
        //so we need to explore the graph one node at a time
        //create a copy with the node value, and add the clones of neighbors of og node
        //this means we need to map each node to its clone to add neighbors
        //to traverse the graph we can use dfs
        return helper(node);
    }

    Node* helper(Node* node) //takes pointer to a node in a graph and returns its deep copy
    {
        if(!node) return nullptr;
        if(clones.count(node)) return clones[node];

        Node* copy = new Node(node->val); //makes a clone with nodes val
        clones[node] = copy;

        for(Node* n : node->neighbors) //now we need to add its neighbors
        {
            copy->neighbors.push_back(helper(n));
        }

        return copy;
    }
};

