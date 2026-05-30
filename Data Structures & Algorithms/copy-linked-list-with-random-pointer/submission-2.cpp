/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> clone;

        Node* temp = head;
        while(temp)
        {
            Node* copy = new Node(temp->val);
            clone[temp] = copy;
            temp = temp->next;
        }

        temp = head;
        while(temp)
        {
            clone[temp]->next = clone[temp->next];
            clone[temp]->random = clone[temp->random];
            temp = temp->next;
        }

        return clone[head];
    }
};
