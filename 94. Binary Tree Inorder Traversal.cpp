/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* node, vector<int> & vec)
    {
        if(node != NULL)
        {
            inorder(node->left, vec);
            vec.push_back(node->val);
            inorder(node->right, vec);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        
        inorder(root, ret);
        
        return ret;
    }
};