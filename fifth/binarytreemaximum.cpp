
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
    int sumTree(TreeNode *root) {
        if(root == NULL)
            return 0;

        int right = sumTree(root->right);
        int left = sumTree(root->left);
        int big = root->val;

        if(left != 0)
            result = max(left, result);
        if(right != 0)
            result = max(result, right);
        if(right > 0)
            big += right;
        if(left > 0)
            big += left;

        result = max(big, result);

        big = max(root->val, root->val + right);
        big = max(big, root->val + left);
        return big;
    }
    int maxPathSum(TreeNode* root) {
        result = INT_MIN;
        sumTree(root);
        return result;
    }
};
