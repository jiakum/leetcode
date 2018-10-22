
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
        pair<int, int> subFind(TreeNode *root, int &result) {
            if(root == NULL)
                return pair<int, int>(INT_MIN, INT_MAX);

            pair<int, int> pi;
            pair<int, int> left  = subFind(root->left, result);
            pair<int, int> right = subFind(root->right, result);

            pi.first  = max(root->val, right.first);
            pi.second = min(root->val, left.second);

            if(left.first != INT_MIN)
                result = min(result, root->val - left.first);
            if(right.first != INT_MIN)
                result = min(result, right.second - root->val);

            return pi;
        }
        int getMinimumDifference(TreeNode* root) {
            int result = INT_MAX;

            subFind(root, result);

            return result;
        }
};
