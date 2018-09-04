
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
    vector<vector<int>> result;
    vector<int> vi;

    public:
    bool findSum(vector<int>& candidates, int start, int target) {
        int i = start;

        for(i = start;i < (int)candidates.size();i++) {
            int num = candidates[i];

            if(i > start && candidates[i] == candidates[i - 1])
                continue;

            if(num == target) {
                vi.push_back(candidates[i]);
                result.push_back(vi);
                vi.pop_back();
            } else if(num < target)  {
                vi.push_back(candidates[i]);
                findSum(candidates, i + 1, target - num);
                vi.pop_back();
            }

        }

        return false;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> nums(candidates);

        if(candidates.size() == 0)
            return result;

        sort(nums.begin(), nums.end());
        findSum(nums, 0, target);

        return result;
    }
};


int main(int argc, char **argv)
{
    Solution sol;
    vector<vector<int>> result;
    vector<int> candidates = {2,3,5}, output;
    unsigned int i, j;
    int target = 8;

    result = sol.combinationSum(candidates, target);
    for(i = 0;i < result.size();i++) {
        output = result[i];
        for(j = 0;j < output.size();j++) 
            printf("%d  ", output[j]);
        printf("\n");
    }
    

    return 0;
}
