
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
    int total;
    public:
    int subSum(TreeNode *root) {
        if(root == NULL)
            return 0;
        int left = subSum(root->left);
        int right = subSum(root->right);

        total += abs(left - right);

        return left + right + root->val;
    }
    int findTilt(TreeNode* root) {
        total = 0;
        subSum(root);
        return total;
    }
};
