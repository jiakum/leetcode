
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
        string multiply(string num1, string num2) {
            int size1 = num1.size(), size2 = num2.size();
            int i, j, index;
            char val;
            string result(size1 + size2, '0');

            for(i = size1 - 1;i >= 0;i--) {
                char c1 = num1[i] - '0';
                char plus = 0;
                for(j = size2 - 1;j >= 0;j--) {
                    char c2 = num2[j] - '0';
                    val = c1 * c2 + plus;

                    index = size1 - i + size2 - j - 2;

                    val += result[index] - '0';
                    plus = val / 10;
                    val = val % 10;

                    val += '0';
                    result[index] = val;
                }

                index = size1 - i + size2 - 2;
                while(plus) {
                    index++;
                    val = result[index] - '0' + plus;
                    plus = val / 10;
                    val = val % 10;
                    result[index] = val + '0';
                }
            }

            for(i = result.size()-1;i >0;i--) {
                if(result[i] == '0')
                    result.pop_back();
                else
                    break;
            }

            reverse(result.begin(), result.end());

            return result;
        }
};

int main(int argc, char **argv)
{
    Solution sol;
    string num1, num2;
    char buf[128];
    int m = 123, n = 456;

    snprintf(buf, sizeof(buf), "%d", m);
    num1 = buf;
    snprintf(buf, sizeof(buf), "%d", n);
    num2 = buf;
    cout << sol.multiply(num1, num2) << endl;
    cout << (m * n) << endl;

    return 0;
}
