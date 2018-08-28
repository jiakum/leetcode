
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

class Solution {
    public:
        int reverse(int x) {
            int neg = 0;
            unsigned int val = 0, tmp;

            if(x < 0) {
                x = -x;
                neg = 1;
            }

            while(x) {
                int n = x % 10;

                x /= 10;
                tmp = val * 10 + n;
                if(tmp / 10 != val)
                    val = 0;
                else
                    val = tmp;
            }

            if(val > 0x7fffffff)
                val = 0;

            return neg ? -(int)val: val;
        }
};

int main()
{
    Solution sol;
    int x = 1534236469;

    printf("x:%d, reverse:%d, 0x7fffffff:%d\n", x, sol.reverse(x), 0x7fffffff);
}
