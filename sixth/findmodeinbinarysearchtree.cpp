
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
        int subFind(map<int, int> &result, TreeNode* root) {
            map<int, int>::iterator iter;
            if(root == NULL)
                return 0;

            iter = result.find(root->val);
            if(iter == result.end()) {
                result[root->val] = 1;
                iter = result.find(root->val);            
            } else {
                iter->second++;
            }

            if(root->right) {
                subFind(result, root->right);
            }

            if(root->left) {
                subFind(result, root->left);
            }

            return 0;
        }
        vector<int> findMode(TreeNode* root) {
            map<int, int> result;
            map<int, int>::iterator iter;
            vector<int> vi;

            if(root == NULL)
                return vi;

            subFind(result, root);

            int times = 0;
            for( iter = result.begin();iter != result.end();iter++) {
                times = max(times, iter->second);
            }

            for( iter = result.begin();iter != result.end();iter++) {
                if(times == iter->second)
                    vi.push_back(iter->first);
            }

            return vi;
        }
};
