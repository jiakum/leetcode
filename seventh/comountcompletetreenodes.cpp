
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
        int travesal(TreeNode *root, int left, int right) {
            if(root == NULL)
                return 0;

            if(left == 0) {
                TreeNode *tree = root;
                while(tree) {
                    tree = tree->left;
                    left++;
                }
            }        
            if(right == 0) {
                TreeNode *tree = root;
                while(tree) {
                    tree = tree->right;
                    right++;
                }
            }

            if(left == right)
                return (1 << (left)) - 1;

            int nodes = 1;
            nodes += travesal(root->left, left - 1, 0);
            nodes += travesal(root->right, 0, right - 1);

            return nodes;
        }
        int countNodes(TreeNode* root) {
            return travesal(root, 0, 0);
        }
};
