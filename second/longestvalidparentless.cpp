
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
        int longestValidParentheses(string s) {
            int size = s.size(), i, j, max = 0;

            if(size < 2)
                return max;

            int dp[size];
            memset(dp, 0, sizeof(dp));

            for(i = 1;i < size;i++) {
                if(s[i] == ')' && s[i - 1] == '(') {
                    if(i > 1)
                        dp[i] += dp[i - 2];
                    dp[i] += 2;
                } else if(s[i] == ')') {
                    j = dp[i - 1];
                    if(j != 0) {
                        if(i - j - 1 >= 0) {
                            if(s[i - j - 1] == '(') {
                                dp[i] = dp[i - 1] + 2;
                                if(i - j - 2 >= 0)
                                    dp[i] += dp[i - j - 2];
                            }
                        }
                    }
                }

                if(dp[i] > max)
                    max = dp[i];
            }

            return max;
        }
};


int main(int argc, char **argv)
{
    Solution sol;

    

    return 0;
}
