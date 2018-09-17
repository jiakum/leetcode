
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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> result;
            vector<TreeNode*> cur, last;
            int i;

            if(root == NULL)
                return result;

            last.push_back(root);
            while(!last.empty()) {
                vector<int> vi;

                cur.clear();
                for(i = 0;i < last.size();i++) {
                    root = last[i];

                    vi.push_back(root->val);

                    if(root->left)
                        cur.push_back(root->left);
                    if(root->right)
                        cur.push_back(root->right);
                }

                last = cur;
                result.insert(result.begin(), vi);
            }

            return result;
        }
};
