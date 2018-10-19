
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
        void subSearch(TreeNode *root, int &result, int left) {
            if(root == NULL)
                return;

            if(root->left == NULL && root->right == NULL) {
                if(left)
                    result += root->val;
            } else {
                if(root->left) {
                    subSearch(root->left, result, 1);
                }
                if(root->right) {
                    subSearch(root->right, result, 0);
                }
            }
        }
        int sumOfLeftLeaves(TreeNode* root) {
            int result = 0;

            subSearch(root, result, 0);

            return result;
        }
};
