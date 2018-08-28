
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            vector<int> vec(256, -1);
            int val, max = 0, start = -1;
            unsigned int i;

            for(i = 0;i < s.size();i++) {
                val = s[i];
                if(vec[val] > start)
                    start = vec[val];
                vec[val] = i;

                if((int)i - start > max)
                    max = i - start;
            }

            return max;
        }
};

int main()
{
    Solution sol;
    string s = "dvdf";

    printf("longest substring:%d\n", sol.lengthOfLongestSubstring(s));

    return 0;
}
