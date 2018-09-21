
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
    stack<TreeNode*> parent, pparent, qparent;
    public:
    bool findNode(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(root == NULL)
            return false;

        parent.push(root);
        if(root == p) {
            pparent = parent;
            if(!qparent.empty())
                return true;
        } else if(root == q) {
            qparent = parent;
            if(!pparent.empty())
                return true;
        }
        if(findNode(root->left, p, q))
            return true;
        if(findNode(root->right, p, q))
            return true;
        parent.pop();

        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*,TreeNode*> lmap;
        map<TreeNode*,TreeNode*>::iterator iter;
        TreeNode *node;

        findNode(root, p, q);
        while(!pparent.empty()) {
            node = pparent.top();
            pparent.pop();
            lmap[node] = node;
        }

        while(!qparent.empty()) {
            node = qparent.top();
            qparent.pop();

            iter = lmap.find(node);
            if(iter == lmap.end())
                continue;

            return node;
        }       

        return root;
    }
};
