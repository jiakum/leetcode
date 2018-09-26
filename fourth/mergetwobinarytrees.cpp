
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

        TreeNode *mergeOne(TreeNode *t1, TreeNode *t2) {
            if(t1 == NULL && t2 == NULL)
                return NULL;
            int val = 0;
            if(t1)
                val += t1->val;
            if(t2)
                val += t2->val;

            TreeNode * node = new TreeNode(val);
            return node;
        }

        TreeNode* subMerge(TreeNode *root, TreeNode *t1, TreeNode *t2) {
            if(t1 == NULL && t2 == NULL)
                return root;

            TreeNode *l1 = NULL, *l2 = NULL, *r1 = NULL, *r2 = NULL;
            if(t1) {
                l1 = t1->left;
                r1 = t1->right;
            }
            if(t2) {
                l2 = t2->left;
                r2 = t2->right;
            }
            root->left = mergeOne(l1, l2);
            root->right = mergeOne(r1, r2);

            subMerge(root->left, l1, l2);
            subMerge(root->right, r1, r2);

            return root;
        }

        TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
            TreeNode *root = mergeOne(t1, t2);
            return subMerge(root, t1, t2);
        }
};
