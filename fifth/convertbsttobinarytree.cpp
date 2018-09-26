
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
        int subCreate(TreeNode *root, TreeNode **p, int bigger) {
            if(root == NULL) {
                *p = NULL;
                return bigger;
            }

            TreeNode *node = new TreeNode(0);

            int big = subCreate(root->right, &node->right, bigger);
            int ret = big + root->val;

            node->val = ret;
            *p = node;

            ret = subCreate(root->left, &node->left, ret);

            return ret;
        }
        TreeNode* convertBST(TreeNode* root) {
            TreeNode *node;
            subCreate(root, &node, 0);
            return node;
        }
};
