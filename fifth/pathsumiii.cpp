
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
    int subPath(TreeNode* root, int sum, bool seq) {
        if(root == NULL)
            return 0;
        if(sum == root->val) {
            result++;
        }

        int ret;
        //printf("val:%d, sum:%d, seq:%d\n", root->val, sum, seq);
        ret= subPath(root->left, sum - root->val, true);
        ret = subPath(root->right, sum - root->val, true);
        if(seq == false) {
            ret = subPath(root->right, sum, false);
            ret = subPath(root->left, sum, false);
        }

        return ret;
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;

        result = 0;
        subPath(root, sum, false);

        return result;
    }
};
