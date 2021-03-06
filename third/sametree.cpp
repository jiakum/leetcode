
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
        bool subtree(TreeNode* p, TreeNode* q) {
            if(p && q) {
                if(p->val != q->val)
                    return false;

                return subtree(p->left, q->left) && subtree(p->right, q->right);
            } else if(!p && !q) {
                return true;
            } else {
                return false;
            }
        }
        bool isSameTree(TreeNode* p, TreeNode* q) {
            return subtree(p, q);
        }
};
