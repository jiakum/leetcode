
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
        void subInvertTree(TreeNode *root) {
            if(root == NULL)
                return;

            TreeNode * left = root->left;

            root->left = root->right;
            root->right = left;
            subInvertTree(root->left);
            subInvertTree(root->right);
        }
        TreeNode* invertTree(TreeNode* root) {
            subInvertTree(root);
            return root;
        }
};
