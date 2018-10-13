
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
    void subSearch(TreeNode* root, TreeNode *pn, stack<TreeNode*> &pans
            , stack<TreeNode*> &ancestor) {
        if((root == NULL) || !pans.empty())
            return;

        ancestor.push(root);

        if(root->val > pn->val) {
            subSearch(root->left, pn, pans, ancestor);
        } else if(root->val < pn->val) {
            subSearch(root->right, pn, pans, ancestor);
        } else {
            pans = ancestor;
        }

        ancestor.pop();
    }
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> ancestor, pans, qans;

        subSearch(root, p, pans, ancestor);
        subSearch(root, q, qans, ancestor);

        map<TreeNode*,TreeNode*> lmap;

        while(!pans.empty()) {
            lmap[pans.top()] = pans.top();
            pans.pop();
        }

        while(!qans.empty()) {
            if(lmap.find(qans.top()) != lmap.end())
                return qans.top();

            qans.pop();
        }

        return NULL;
    }
};
