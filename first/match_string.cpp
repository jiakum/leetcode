
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isMatch(string text, string pattern) {
            int m = text.size(), n = pattern.size();
            bool dp[m + 1][n + 1], match;
            int i, j;

            dp[m][n] = true;

            for(i = m - 1;i >= 0;i--) 
                dp[i][n] = false;

            for(j = n - 1;j >= 0;j--) {
                if(j < n - 1 && pattern[j + 1] == '*')
                    dp[m][j] = dp[m][j + 2];
                else
                    dp[m][j] = false;
            }

            for(i = m - 1;i >= 0;i--) {
                for(j = n - 1;j >= 0;j--) {
                    match = (text[i] == pattern[j]) || (pattern[j] == '.');

                    if(j < n - 1 && pattern[j + 1] == '*') {
                        dp[i][j] = (dp[i][j + 2]) || (match && dp[i + 1][j]);
                    } else {
                        dp[i][j] = match && dp[i + 1][j + 1];
                    }
                }
            }

            return dp[0][0];
        }
};

int main()
{
    Solution sol;
    string s = "bbab", p = "b*a*";

    printf("is match:%d\n", sol.isMatch(s, p));


    return 0;
}
