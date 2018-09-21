
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
        int kthSmallest(TreeNode* root, int k) {
            stack<TreeNode*> history;
            TreeNode * node = root;

            while(node || !history.empty()) {
                while(node) {
                    history.push(node);
                    node = node->left;
                }

                node = history.top();
                history.pop();
                if(--k <= 0) {
                    return node->val;
                }
                node = node->right;
            }

            return -1;
        }
};
