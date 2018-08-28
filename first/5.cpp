
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include <string>
#include <iostream>

using namespace std;

static inline int palindrome(string &s, int index)
{
    int ret, max, ptr, size = s.size();

    max = 0;
    ptr = 0;
    while(index - ptr >= 0 && index + ptr + 1 < size) {
        if(s[index + ptr + 1] != s[index - ptr])
            break;

        ptr++;
        max += 2;
    }

    ret = max;
    max = 1;
    ptr = 0;
    while(index - ptr -1 >= 0 && index + ptr + 1 < size) {
        if(s[index + ptr + 1] != s[index - ptr - 1])
            break;

        ptr++;
        max += 2;
    }

    if(max > ret)
        ret = max;

    return ret;
}

class Solution {
    public:
        string longestPalindrome(string s) {
            int max = 0, mid = 0, i, ret;
            string result;

            for(i = 0;i < (int)s.size();i++) {
                ret = palindrome(s, i);
                if(ret > max) {
                    max = ret;
                    mid = i;
                }
            }

            if(max & 0x01) {
                for(i = mid - max / 2;i <= mid + max / 2;i++)
                    result.push_back(s[i]);
            } else {
                for(i = mid - (max / 2) + 1;i <= mid + max / 2;i++)
                    result.push_back(s[i]);
            }

            return result;
        }
};

int main()
{
    Solution sol;
    string s = "abdba";

    cout << sol.longestPalindrome(s) << endl;

    return 0;
}
