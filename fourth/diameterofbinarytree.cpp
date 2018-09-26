
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
    vector<pair<int,int>> vi;
    public:
    static bool compare(pair<int,int> &left, pair<int,int> &right) {
        return left.first + left.second < right.first + right.second;
    }
    int maxDepth(TreeNode *root) {
        if(root == NULL)
            return 1;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        pair<int,int> p = pair<int,int>(left, right);

        vi.push_back(p);

        return max(right, left) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        maxDepth(root);
        sort(vi.begin(), vi.end(), compare);
        return vi.back().first + vi.back().second - 2;
    }
};
