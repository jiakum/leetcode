
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
        bool sameTree(TreeNode *s, TreeNode *t) {
            if(s == NULL && t == NULL)
                return true;
            else if(s && t) {
                if(s->val == t->val && 
                        sameTree(s->left, t->left) && 
                        sameTree(s->right, t->right))
                    return true;
            }

            return false;
        }
        bool findTree(TreeNode *s, TreeNode *t) {
            if(s == NULL && t == NULL)
                return true;
            else if(s && t) {
                if(sameTree(s, t))
                    return true;

                return (findTree(s->left, t) || findTree(s->right, t));
            }

            return false;
        }
        bool isSubtree(TreeNode* s, TreeNode* t) {
            return findTree(s, t);
        }
};
