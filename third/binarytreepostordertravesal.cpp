
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            vector<TreeNode*> history;
            TreeNode *node = root;

            while(node || !history.empty()) {
                while(node) {
                    history.push_back(node);
                    node = node->left;
                }

                node = history.back();
                history.pop_back();
                result.push_back(node->val);
                node = node->right;
            }

            return result;
        }
    private:
        enum {
            TRAVESAL_LEFT,
            TRAVESAL_RIGHT,
            TRAVESAL_NODE
        };
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            stack<TreeNode*> history;
            stack<int> hstate;
            vector<int> result;
            int state = TRAVESAL_LEFT;

            if(root == NULL)
                return result;

            history.push(NULL);
            hstate.push(TRAVESAL_NODE);
            while(!history.empty()) {
                switch(state) {
                    case TRAVESAL_LEFT:
                        while(root) {
                            history.push(root);
                            hstate.push(TRAVESAL_RIGHT);
                            root = root->left;
                        }

                        root = history.top();
                        history.pop();
                        state = hstate.top();
                        hstate.pop();
                        break;
                    case TRAVESAL_RIGHT:
                        history.push(root);
                        hstate.push(TRAVESAL_NODE);
                        root = root->right;
                        state = TRAVESAL_LEFT;
                        break;
                    case TRAVESAL_NODE:
                        if(root == NULL)
                            break;
                        result.push_back(root->val);

                        root = history.top();
                        history.pop();
                        state = hstate.top();
                        hstate.pop();
                        break;
                }
            }

            return result;
        }

};

int main()
{
    Solution sol;
    TreeNode* root;
    vector<int> nums = {-10,-3,0,5,9};
    int i;

    root = sol.sortedArrayToBST(nums);
    nums = sol.postorderTraversal(root);

    for(i = 0;i < (int)nums.size();i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n");

    return 0;
}
