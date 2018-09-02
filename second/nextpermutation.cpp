
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int i = nums.size() - 2, tmp, j;
            while (i >= 0 && nums[i] >= nums[i + 1]) {
                i--;
            }
            if (i >= 0) {
                j = nums.size() - 1;
                while (j >= 0 && nums[j] <= nums[i]) {
                    j--;
                }
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
            printf("i:%d,j:%d\n", i, j);
            reverse(nums, i + 1);
        }

        void reverse(vector<int> &nums, int start) {
            int i = start, j = nums.size() - 1, tmp;
            while (i < j) {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i++;
                j--;
            }
        }
};

int main(int argc, char **argv)
{
    Solution sol;
    vector<int> nums = {1 , 3, 2};
    int i;

    sol.nextPermutation(nums);
    for(i = 0;i < (int)nums.size();i++)
        printf("%d\n", nums[i]);
    

    return 0;
}
