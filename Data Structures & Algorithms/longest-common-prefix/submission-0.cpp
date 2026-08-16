class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode();
        for(string s : strs)
        {
            insert(s, root);
        }

        TrieNode* curr = root;
        string ans;
        while(curr->children.size() == 1 && !curr->endOfWord)
        {
            auto it = curr->children.begin();
            ans += it->first;
            curr = it->second;
        }

        return ans;

    }

    void insert(string str, TrieNode* root)
    {
        TrieNode* curr = root;
        for(char c : str)
        {
            if(!curr->children[c]) curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }

        curr->endOfWord = true;                     
    }
};