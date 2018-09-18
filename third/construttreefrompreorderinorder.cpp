
class Solution {
    public:
        TreeNode* subbuildtree(vector<int>& preorder, int start, int end, int &index) {
            if(start > end)
                return NULL;

            int i, pos, val = preorder[index];
            pos = imap.find(val)->second;
            if(!(pos >= start && pos <= end))
                return NULL;

            index++;
            TreeNode *node = new TreeNode(val);

            node->left  = subbuildtree(preorder, start, pos - 1, index);
            node->right = subbuildtree(preorder, pos + 1, end, index);

            return node;
        }
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int i, size = preorder.size(), index = 0;

            if(size == 0)
                return NULL;

            imap.clear();
            for(i = 0;i < size;i++) {
                imap[inorder[i]] = i;
            }

            return subbuildtree(preorder, 0, size - 1, index);
        }
    private:
        map<int, int> imap;
};
