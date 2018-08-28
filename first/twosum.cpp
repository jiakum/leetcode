
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <map>

using namespace std;  


class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> result;
            map<int,int> vmap;
            unsigned int i;

            for(i = 0;i < nums.size();i++) {
                int val = nums[i];
                int other = target - val;

                if(vmap.find(other) != vmap.end()) {
                    result.push_back(vmap.find(other)->second);
                    result.push_back(i);

                    break;
                }

                vmap[val] = i;
            }
            
            return result;
        }
};

int main(int argc, char **argv)
{
    vector<int> nums = {2, 7, 11, 15}, result;
    class Solution sol;

    result = sol.twoSum(nums, 9);

    printf("%d,%d\n", nums[0], nums[1]);
    printf("%d,%d\n", result[0], result[1]);

    return 0;
}
