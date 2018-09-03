
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string s;
            int size = strs.size(), i, j;

            if(size == 0)
                return s;
            else if(size == 1)
                return strs[0];

            for(i = 0;i < (int)strs[0].size();i++) {
                char c = strs[0][i];

                for(j = 1;j < (int)strs.size();j++) {
                    if(strs[j][i] != c)
                        return s;
                }

                s.push_back(c);
            }

            return s;
        }
};

int main()
{
    Solution sol;
    vector<string> vs;

    vs.push_back(string("flower"));
    vs.push_back(string("flow"));
    vs.push_back(string("flight"));

    cout << sol.longestCommonPrefix(vs);

    return 0;
}
