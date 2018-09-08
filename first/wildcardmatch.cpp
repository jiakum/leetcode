
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
    // return value:
    // 0: reach the end of s but unmatched
    // 1: unmatched without reaching the end of s
    // 2: matched
    int isSubstrMatch(string& s, string& p, int si, int pi) {
        if (si == (int)s.size() && pi == (int)p.size()) return 2;
        if (si == (int)s.size() && p[pi] != '*') return 0;
        if (pi == (int)p.size()) return 1;
        if (p[pi] == '*') {
            if (pi+1 < (int)p.size() && p[pi+1] == '*') 
                return isSubstrMatch(s, p, si, pi+1); // skip duplicate '*'
            for(int i = 0; i <= (int)s.size()-si; ++i) {
                int ret = isSubstrMatch(s, p, si+i, pi+1);
                if (ret == 0 || ret == 2) return ret; 
            }
        }
        if (p[pi] == '?' || s[si] == p[pi])
            return isSubstrMatch(s, p, si+1, pi+1);
        return 1;
    }    

    public:
    bool isMatch(string s, string p) {
        return isSubstrMatch(s, p, 0, 0) > 1;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    string s = "baaabbabbbaabbbbbbabbbaaabbaabbbbbaaaabbbbbabaaaaabbabbaabaaababaabaaabaaaabbabbbaabbbbbaababbbabaaabaabaaabbbaababaaabaaabaaaabbabaabbbabababbbbabbaaababbabbaabbaabbbbabaaabbababbabababbaabaabbaaabbba";
    string p = "*b*ab*bb***abba*a**ab***b*aaa*a*b****a*b*bb**b**ab*ba**bb*bb*baab****bab*bbb**a*a*aab*b****b**ba**abba";

    cout << "is match:" << sol.isMatch(s, p) << endl;
    

    return 0;
}
