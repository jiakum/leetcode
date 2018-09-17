
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

                return subtree(p->right, q->left) && subtree(p->left, q->right);
            } else if(!p && !q) {
                return true;
            } else {
                return false;
            }
        }
        bool isSymmetric(TreeNode* root) {
            if(root == NULL)
                return true;
            return subtree(root->left, root->right);
        }
};
