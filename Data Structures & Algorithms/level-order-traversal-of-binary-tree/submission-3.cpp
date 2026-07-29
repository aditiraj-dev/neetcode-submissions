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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            vector<int> level;
            int size = q.size();
            
            for(int i = size; i > 0; i--) //basically, originally how many nodes are in queue, push all their children in level
            {
                TreeNode* node = q.front(); //store current node and then its childre
                q.pop();
                if(node)
                {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }

            if(!level.empty()) res.push_back(level);
        }

        return res;
    }
};
