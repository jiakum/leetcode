
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
        void subSearch(TreeNode *root, string &result) {
            if(root == NULL) {
                result.append("()");
                return;
            }

            char num[16];
            snprintf(num, sizeof(num), "(%d", root->val);
            result.append(num);

            if(root->left == NULL && root->right == NULL) {
                result.append(")");
                return;
            }

            subSearch(root->left, result);
            if(root->right)
                subSearch(root->right, result);

            result.append(")");
        }
        string tree2str(TreeNode* t) {
            string result;

            subSearch(t, result);

            return result.substr(1, result.size() - 2);
        }
};
