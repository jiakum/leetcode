
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            int val = 0, n;

            if(x < 0)
                return false;
            else if(x / 10 == 0)
                return true;
            else if(x % 10 == 0)
                return false;

            while(x > val) {
                n = x % 10;
                x /= 10;

                val = val * 10 + n;
                if(val == x || (val == x / 10 && val) )
                    return true;
            }

            return false;
        }
};

int main()
{
    Solution sol;
    int x = 10;

    cout << sol.isPalindrome(x) << endl;

    return 0;
}
