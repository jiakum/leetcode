
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
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> result;
            vector<int> sortnums(nums);
            int i, j, k, n, size = nums.size();

            if(size < 4)
                return result;

            sort(sortnums.begin(), sortnums.end());

            for(i = 0;i < size - 3;i++) {
                int ni = sortnums[i];

                if(ni > 0 && ni > target)
                    break;

                if(i > 0 && ni == sortnums[i - 1])
                    continue;

                for(j = size - 1;j > i + 2;j--) {
                    int nj = sortnums[j];

                    if(nj < 0 && ni + nj < target)
                        break;

                    if(j < size - 1 && nj == sortnums[j + 1])
                        continue;

                    for(k = i + 1, n = j - 1;k < n;) {
                        int nk = sortnums[k];
                        int nn = sortnums[n];
                        int value = ni + nj + nk + nn;
                        
                        if(value == target) {
                            vector<int> vi;

                            vi.push_back(ni);
                            vi.push_back(nk);
                            vi.push_back(nn);
                            vi.push_back(nj);
                            result.push_back(vi);
                            do {
                                k++;
                            } while(nk == sortnums[k] && k < n);
                            do {
                                n--;
                            } while(nn == sortnums[n] && k < n);
                        } else if(value > target) {
                            n--;
                        } else {
                            k++;
                        }
                    }
                }
            }

            return result;
        }
};

int main(int argc, char **argv)
{
    Solution sol;
    vector<int> nums = {1,-2,-5,-4,-3,3,3,5};
    vector<vector<int>> result;
    int i, target = -11;

    result = sol.fourSum(nums, target);
    for(i = 0; i < (int)result.size();i++) {
        printf("line %d: %d, %d, %d, %d\n", i, result[i][0], result[i][1], result[i][2], result[i][3]);
    }

    return 0;
}
