class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c: word)
        {
            if(!curr->children.count(c))
            {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }

        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return helper(word, 0, root);
    }

    bool helper(string word, int i, TrieNode* root)
    {
        TrieNode* curr = root;
        for(int j = i; j < word.size(); j++)
        {
            char c = word[j];
            if(c == '.')
            {
                for(auto& [ch, child] : curr->children)
                {
                    if(child != nullptr && helper(word, j + 1, child)) return true;
                }
                return false;
            }
            else
            {
                if(!curr->children[c]) return false;

                curr = curr->children[c];
            }
        }

        return curr->endOfWord;
    }
};
