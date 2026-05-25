/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int res = 0;

    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        dfs(root, root->val);

        return res;
    }

    void dfs(TreeNode* root, int maxN)
    {
        if(!root) return;

        if(root->val >= maxN) res++;
        maxN = max(root->val, maxN);
        dfs(root->left, maxN);
        dfs(root->right, maxN);
    }
};
