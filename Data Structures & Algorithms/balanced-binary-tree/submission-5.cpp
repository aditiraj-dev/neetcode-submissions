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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        int l = getHeight(root->left);
        int r = getHeight(root->right);

        return isBalanced(root->left) && isBalanced(root->right) && (abs(l - r) <=1);
    }

    int getHeight(TreeNode* root)
    {
        if(root==nullptr) return -1;

        int res = 1 + max(getHeight(root->left), getHeight(root->right));

        return res;
    }
};
