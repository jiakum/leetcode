
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        int numsmaller; // Num of smaller values
        int num; // Num of this value
        TreeNode(int v) : val(v), left(NULL), right(NULL),numsmaller(0), num(1) {};
};

class Solution {
    private:
        void insert(TreeNode *root, int val, int &numsmaller) {
            while (true) {
                if (val > root->val) {
                    numsmaller += root->num + root->numsmaller;
                    if (root->right == nullptr) {
                        root->right = new TreeNode(val);
                        break;
                    }
                    root = root->right;
                } else if (val < root->val) {
                    root->numsmaller++;
                    if (root->left == nullptr) {
                        root->left = new TreeNode(val);
                        break;
                    }
                    root = root->left;
                } else {
                    root->num++;
                    numsmaller += root->numsmaller;
                    break;
                }
            }
        }
    public:
        vector<int> countSmaller(vector<int> &nums) {
            if (nums.empty()) 
                return vector<int>();

            TreeNode *root = new TreeNode(nums.back());
            vector<int> res(nums.size());

            res.push_back(0);

            int i = nums.size() - 1;
            for (auto ri = nums.rbegin() + 1; ri != nums.rend(); ri++) {
                int numsmaller = 0;
                insert(root, *ri, numsmaller);
                res[--i] = numsmaller;
            }

            return res;
        }
};
