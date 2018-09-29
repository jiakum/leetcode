
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
    int result;
    public:
    int sameVal(TreeNode *root, int num) {
        if(root == 0)
            return 0;

        int ret, right = 0, left = 0;
        if(root->right) {
            if(root->right->val == root->val)
                right = sameVal(root->right, 1);
            else
                sameVal(root->right, 0);
        }
        if(root->left) {
            if(root->left->val == root->val)
                left = sameVal(root->left, 1);
            else
                sameVal(root->left, 0);
        }

        ret = max(num + left, num + right);
        result = max(ret, result);
        result = max(result, left + right);

        return ret;
    }
    int longestUnivaluePath(TreeNode* root) {
        result = 0;

        sameVal(root, 0);
        return result;
    }
};
