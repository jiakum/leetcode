
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    public:
        void subconntect(TreeLinkNode *left, TreeLinkNode *right) {
            if(left == NULL && right == NULL)
                return;
            else if(left) {
                left->next = right;
                if(right) {
                    subconntect(left->left, left->right);
                    subconntect(left->right, right->left);
                    subconntect(right->left, right->right);
                } else {
                    subconntect(left->left, left->right);                
                }
            }
        }
        void connect(TreeLinkNode *root) {
            subconntect(root, NULL);
        }
};
