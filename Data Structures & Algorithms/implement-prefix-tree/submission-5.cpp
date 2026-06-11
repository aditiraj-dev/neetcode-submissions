class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word)
        {
            if(curr->children[c] == nullptr) curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }

        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c : word)
        {
            if(curr->children[c] == nullptr) return false;;
            curr = curr->children[c];
        }

        if(curr->endOfWord == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix)
        {
            if(curr->children[c] == nullptr) return false;
            curr = curr->children[c];
        }

        return true;
    }
};
