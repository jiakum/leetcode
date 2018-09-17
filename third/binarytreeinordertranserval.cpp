
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
    enum SEARCH_STATE{
        SEARCH_LEFT,
        SEARCH_RIGHT,
        SEARCH_NODE
    };
    public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> history;
        TreeNode *node = root;

        while(node || !history.empty()) {
            while(node) {
                history.push_back(node);
                node = node->left;
            }

            node = history.back();
            history.pop_back();
            result.push_back(node->val);
            node = node->right;
        }

        return result;
    }
};
