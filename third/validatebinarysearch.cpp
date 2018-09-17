
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
        bool isValidBST(TreeNode* root) {
            stack<TreeNode*> history;
            TreeNode *node = root;
            int last, first = 1;

            while(node || !history.empty()) {
                while(node) {
                    history.push(node);
                    node = node->left;
                }

                node = history.top();
                history.pop();

                if(first == 1) 
                    first = 0;
                else if(node->val <= last) 
                    return false;
                last = node->val;
                node = node->right;
            }

            return true;
        }
};
