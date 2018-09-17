
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
        TreeNode* buildTreeUtil(vector<int>& inorder, vector<int>& postorder,int inend,int instart,int postindex) 
        {
            if(instart>inend)
            {
                return NULL;
            }

            TreeNode *root = new TreeNode(postorder[postindex]);

            int index=0;

            for(int i=inend;i>=instart;i--)
            {
                if(inorder[i]==root->val)
                {
                    index=i;
                    break;                     
                }

            }

            root->right=buildTreeUtil(inorder,postorder,inend,index+1,postindex-1);
            root->left=buildTreeUtil(inorder,postorder,index-1,instart,postindex-(inend-index)-1);

            return root;
        }

        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            TreeNode *root=buildTreeUtil(inorder,postorder,inorder.size()-1,0,postorder.size()-1);

            return root;
        }
};
