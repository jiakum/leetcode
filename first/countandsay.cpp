
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
        string countAndSay(int n) {
            int i, j;
            string result, last;

            if(n == 0)
                return result;

            last = "1";
            for(i = 2;i <= n;i++) {
                int size = last.size();

                for(j = 0;j < size;j++) {
                    int num = 1;
                    char c = last[j];
                    while(j < size - 1) {
                        c = last[j];
                        if(c == last[j + 1]) {
                            num++;
                            j++;
                        } else {
                            break;
                        }
                    }

                    result.push_back(num + '0');
                    result.push_back(c);
                }

                last = result;
                result.clear();
            }

            result = last;

            return result;
        }
};

int main(int argc, char **argv)
{
    Solution sol;
    int n = 10;

    cout << sol.countAndSay(n) << endl;

    return 0;
}
