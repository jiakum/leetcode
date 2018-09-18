
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
        TreeNode* subbuildtree(vector<int>& postorder, int start, int end, int &index) {
            if(start > end)
                return NULL;

            int i, pos, val = postorder[index];
            pos = imap.find(val)->second;
            if(!(pos >= start && pos <= end))
                return NULL;

            index--;
            TreeNode *node = new TreeNode(val);

            node->right = subbuildtree(postorder, pos + 1, end, index);
            node->left  = subbuildtree(postorder, start, pos - 1, index);

            return node;
        }
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            int i, size = inorder.size(), index = size - 1;

            if(size == 0)
                return NULL;

            imap.clear();
            for(i = 0;i < size;i++) {
                imap[inorder[i]] = i;
            }

            return subbuildtree(postorder, 0, size - 1, index);
        }
    private:
        map<int, int> imap;
};
