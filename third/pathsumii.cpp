
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
        void hasPathSum(vector<vector<int>> &result, vector<int> &vi, TreeNode* root, int sum) {
            if(root == NULL)
                return;

            vi.push_back(root->val);
            if(root->left == NULL && root->right == NULL) {
                if(root->val == sum) {
                    result.push_back(vi);
                }                
                vi.pop_back();
                return;
            }

            hasPathSum(result, vi, root->left, sum - root->val);
            hasPathSum(result, vi, root->right, sum - root->val);
            vi.pop_back();
        }
        vector<vector<int>> pathSum(TreeNode* root, int sum) {
            vector<vector<int>> result;
            vector<int> vi;

            hasPathSum(result, vi, root, sum);

            return result;
        }
};
