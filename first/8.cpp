
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string>

using namespace std;

class Solution {
    public:
        int myAtoi(string str) {
            int val = 0, tmp;
            int i = 0, neg = 0;

            while(i < (int)str.size() && str[i] == ' ')
                i++;

            if(str[i] == '-') {
                neg = 1;
                i++;
            } else if(str[i] == '+') {
                i++;
            }

            if(str[i] < '0' || str[i] > '9')
                return val;

            while(str[i] >= '0' && str[i] <= '9') {
                tmp = val * 10 + (str[i] - '0');

                if(tmp / 10 != val) {
                    return neg ? -2147483648 : 0x7fffffff;
                } else {
                    val = tmp;
                }
                i++;
            }

            printf("val:%u\n", val);

            return neg ? -(int)val : val;
        }
};

int main()
{
    Solution sol;
    string s = "2147483648";

    printf("get value:%d\n", sol.myAtoi(s));
    return 0;
}
