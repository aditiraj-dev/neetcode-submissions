class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word)
        {
            if(cur->children[c] == nullptr)
            {
                cur->children[c] = new TrieNode;
            }
            cur = cur->children[c];
        }

        cur->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0 , root);
    }

    bool dfs(string word, int j, TrieNode* root)
    {
        TrieNode* cur = root;

        for(int i = j; i < word.size(); i++)
        {
            char c = word[i];
            if(c == '.')
            {
                for(auto& pair : cur->children)
                {
                    if(pair.second && dfs(word, i + 1, pair.second)) return true;
                }

                return false;
            }
            else
            {
                if(cur->children[c] == nullptr)
                {
                    return false;
                }
                cur = cur->children[c];
            }
        }

        return cur->endOfWord;
    }
};
