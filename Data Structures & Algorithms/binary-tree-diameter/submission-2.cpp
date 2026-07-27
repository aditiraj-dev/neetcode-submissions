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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int curr = maxDepth(root->left) + maxDepth(root->right);

        return max(curr, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }

    int maxDepth(TreeNode* root)
    {
        if(!root) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }
};
