
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
        TreeNode* buildtree(vector<int>& nums, int start, int end) {
            if(start > end)
                return NULL;

            int n = (start + end) / 2;
            TreeNode *node = new TreeNode(nums[n]);
            node->left = buildtree(nums, start, n - 1);
            node->right = buildtree(nums, n + 1, end);

            return node;
        }
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            if(nums.size() == 0)
                return NULL;
            return buildtree(nums, 0, nums.size() - 1);
        }
};
