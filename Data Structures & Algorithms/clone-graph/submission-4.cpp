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
        return helper(node); 
    }

    Node* helper(Node* node) //returns deep copy of node and its neighbors
    {
        if(!node) return nullptr;
        if(clones.count(node)) return clones[node];

        Node* copy = new Node(node->val);
        clones[node] = copy;

        for(Node* n : node->neighbors)
        {
            copy->neighbors.push_back(helper(n));
        }

        return clones[node];
    }
};
