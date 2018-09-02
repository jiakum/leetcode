
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
        int divide(int dividend, int divisor) {
            unsigned int dend, dsor, value, tmp, result = 0;
            int flag, i, j;

            if(dividend == 0)
                return result;
            else if(divisor == (int)0x80000000) {
                if(dividend == divisor)
                    return 1;
                return 0;
            }

            if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
                flag = 1;
            } else {
                flag = -1;
            }

            if(dividend < 0)
                dend = -dividend;
            else
                dend = dividend;
            if(divisor < 0)
                dsor = -divisor;
            else
                dsor = divisor;

            value = 0;
            for(i = 0;i < 32;i++) {
                tmp = dsor;

                if(dend < value + tmp)
                    break;

                for(j = 1;j < 32;j++) {
                    tmp = dsor << j;
                    if(dend == value + tmp) {
                        break;
                    } else if(dend < value + tmp) {
                        j--;
                        break;
                    }
                }

                value += dsor << j;
                result += 1 << j;
                printf("i:%d,j:%d,value:%u,result:%x, flag:%d\n", i, j, value, result, flag);
            }

            printf("i:%d,j:%d,value:%u,result:%x, flag:%d\n", i, j, value, result, flag);
            if(result == 0x80000000) {
                return flag == -1 ? (int)0x80000000 : 0x7fffffff;
            } else {
                return flag == -1 ? -(int)result: (int)result;
            }
        }
};


int main(int argc, char **argv)
{
    Solution sol;
    int dividend = -2147483648, divisor = 2;

    printf("dividend:%d, divisor:%d, result:%d\n", 
            dividend, divisor, sol.divide(dividend, divisor));
    

    return 0;
}
