class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {};
};


class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* left; //before least recent
    Node* right; //after most recent

    void remove(Node* node)
    {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) //insert before right
    {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        Node* node = cache[key];
        remove(node);
        insert(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(cache.count(key))
        {
            remove(cache[key]);
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if(cache.size() > capacity)
        {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
