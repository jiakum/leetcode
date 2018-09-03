
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
        int search(vector<int>& nums, int target) {
            int size = nums.size(), i, j;

            if(size == 0)
                return -1;

            i = 0; j = size - 1;
            while(i + 1 < j && nums[i] != target && nums[j] != target) {
                int half = (i + j) / 2;

                printf("i:%d,j:%d,half:%d\n", i, j, half);
                if(target > nums[half]) {
                    if(nums[i] > nums[j]) {
                        if(nums[half] > nums[j] || target < nums[j]) {
                            i = half;
                        } else {
                            j = half;
                        }
                    } else {
                        i = half;
                    }
                } else if(target < nums[half]) {
                    if(nums[i] > nums[j]) {
                        if(nums[half] < nums[j] || target > nums[j]) {
                            j = half;
                        } else {
                            i = half;
                        }          
                    } else {
                        j = half;
                    }
                } else {
                    return half;
                }

                printf("i:%d,j:%d,half:%d\n", i, j, half);
            }

            if(nums[i] == target)
                return i;
            else if(nums[j] == target)
                return j;
            else
                return -1;
        }
};

int main(int argc, char **argv)
{
    Solution sol;
    vector<int> nums1 = {4,5,6,7,0,1,2};
    int target = 5;

    printf("find target:%d in nums1, index:%d\n", target, sol.search(nums1, target));
    

    return 0;
}
