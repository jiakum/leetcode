
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
        int height(TreeNode *node, int h) {
            if(node == NULL)
                return h;

            return max(height(node->left, h + 1), height(node->right, h + 1));
        }
        bool isBalanced(TreeNode* root) {
            if(root == NULL)
                return true;

            if(abs(height(root->left, 1) - height(root->right, 1)) > 1)
                return false;
            return isBalanced(root->left) && isBalanced(root->right);
        }
};
