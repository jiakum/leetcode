
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
        int i = start, j = 0;

        for(i = start;i < (int)candidates.size();i++) {
            int num = candidates[i];

            printf("start:%d,target:%d, i:%d, j:%d\n", start, target, i, j);
            j = 0;
            while(num <= target)  {
                j++;
                vi.push_back(candidates[i]);
                if(num == target) {
                    printf("found:start:%d,target:%d, i:%d, j:%d\n", start, target, i, j);
                    result.push_back(vi);
                    break;
                }
                findSum(candidates, i + 1, target - num);
                num += candidates[i];
            }

            while(j--)
                vi.pop_back();
        }

        return false;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        if(candidates.size() == 0)
            return result;

        findSum(candidates, 0, target);

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
