
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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<TreeNode*> stn, last;
            vector<vector<int>> result;
            int i;
            int dir = 1;

            if(root == NULL)
                return result;

            last.push_back(root);
            while(!last.empty()) {
                vector<int> vi;
                stn = last;
                last.clear();

                for(i = 0;i < stn.size();i++) {
                    TreeNode *node = stn[i];
                    vi.push_back(node->val);
                }
                for(i = stn.size() - 1;i >= 0;i--) {
                    TreeNode *node = stn[i];
                    if(dir) {
                        if(node->right)
                            last.push_back(node->right);
                        if(node->left)
                            last.push_back(node->left);
                    } else {
                        if(node->left)
                            last.push_back(node->left);     
                        if(node->right)
                            last.push_back(node->right);               
                    }

                }

                dir = !dir;
                result.push_back(vi);
            }

            return result;
        }
};
