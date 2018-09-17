
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
        int height(TreeNode *root, int h) {
            if(root == NULL)
                return h;

            int left = height(root->left, h + 1);
            int right = height(root->right, h + 1);      
            if(left == h  + 1|| right == h + 1)
                return max(left, right);
            return min(left, right);
        }
        int minDepth(TreeNode* root) {

            return height(root, 0);
        }
};
