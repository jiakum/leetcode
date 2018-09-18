
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
    int leafAdd(TreeNode* root, int num) {
        num = num * 10 + root->val;
        if(root->left == NULL && root->right == NULL) {
            result += num;
            return num;
        }

        if(root->left) {
            leafAdd(root->left, num);
        }
        if(root->right) {
            leafAdd(root->right, num);
        }

        return num;
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;

        result = 0;
        leafAdd(root, 0);
        return result;
    }
};
