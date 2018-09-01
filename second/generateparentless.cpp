
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

static void subgenerate(vector<string> &result, string line, int left, int right, int target)
{
    int i;

    if((int)line.size() == target * 2) {
        result.push_back(line);
        return;
    }
    
    if(left < target)
        subgenerate(result, line + '(', left + 1, right, target);

    if(right < left)
        subgenerate(result, line + ')', left, right + 1, target);
}

class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> result;
            string s;

            if(n == 0)
                return result;

            subgenerate(result, s, 0, 0, n);

            return result;
        }
};

int main(int argc, char **argv)
{
    Solution sol;
    vector<string> result;
    int i, n = 3;

    result = sol.generateParenthesis(n);
    for(i = 0;i < (int)result.size();i++) {
        cout << result[i] << endl;
    }

    return 0;
}
