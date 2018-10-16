
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
        void subFind(TreeNode *root, string &str, vector<string> &result) {
            if(root == NULL)
                return;

            char num[16];
            int size = str.size();

            if(size)
                snprintf(num, sizeof(num), "->%d", root->val);
            else
                snprintf(num, sizeof(num), "%d", root->val);

            str.append(num);
            if(root->left == NULL && root->right == NULL) {
                result.push_back(str);
            } else {
                subFind(root->right, str, result);
                subFind(root->left, str, result);
            }

            str.erase(size);
        }
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> result;
            string str;

            subFind(root, str, result);

            return result;
        }
};
