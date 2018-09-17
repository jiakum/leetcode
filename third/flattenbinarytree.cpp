
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
        void flatten(TreeNode* root) {
            TreeNode *node;
            stack<TreeNode*> history, all;

            if(root == NULL)
                return;

            while(root || !history.empty()) {
                while(root) {
                    history.push(root);
                    all.push(root);
                    root = root->left;
                }

                root = history.top();
                history.pop();
                root = root->right;
            }

            TreeNode *last = all.top();
            last->left = NULL;
            last->right = NULL;
            all.pop();
            while(!all.empty()) {
                node = all.top();
                all.pop();

                node->right = last;
                node->left = NULL;
                last = node;
            }

            return;
        }
};
