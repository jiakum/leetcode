
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
        bool subSearch(unordered_set<int> &data,TreeNode* root, int k) {
            if(root == NULL)
                return false;

            if(data.find(k - root->val) != data.end())
                return true;

            data.insert(root->val);

            return subSearch(data, root->left, k) || subSearch(data, root->right, k);
        }
        bool findTarget(TreeNode* root, int k) {
            unordered_set<int> data;
            stack<TreeNode*> history;

            while(root || !history.empty()) {
                while(root) {
                    history.push(root);
                    root = root->left;
                }

                root = history.top();
                history.pop();

                if(data.find(k - root->val) != data.end())
                    return true;
                data.insert(root->val);

                root = root->right;
            }

            return false;
        }
};
