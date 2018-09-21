
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

#define USE_QSORT (1)
#if USE_QSORT
static int qcompare(const void * a, const void * b) {
    int left = *(int *)a, right = *(int *)b;
    char lf[32], lr[32];
    snprintf(lf, sizeof(lf), "%d%d", left, right);
    snprintf(lr, sizeof(lr), "%d%d", right, left);

    return strcmp(lr, lf);
}
#else
static bool compare(int left, int right) {
    char lf[32], lr[32];
    snprintf(lf, sizeof(lf), "%d%d", left, right);
    snprintf(lr, sizeof(lr), "%d%d", right, left);

    return strcmp(lf, lr) > 0 ? true: false;
}
#endif

class Solution {
    public:
        static inline char getNum(const char **pl) {
            const char *ptr = *pl;
            if(*ptr == '\0') {
                return 0;
            } else {
                char ret = *ptr - '0';

                *pl = ptr + 1;
                return ret;
            }
        }
        string largestNumber(vector<int>& nums) {
            int size = nums.size();
#if USE_QSORT
            int snums[size];

            for(int i = 0;i < size;i++) {
                snums[i] = nums[i];
            }

            qsort(snums, nums.size(), sizeof(int), qcompare);
#else
            vector<int> snums(nums);
            sort(snums.begin(), snums.end(), compare);
#endif
            printf("sort success\n"); fflush(stdout);
            string result;
            for(int i = 0;i < size;i++) {
                char lf[32];
                snprintf(lf, sizeof(lf), "%d", snums[i]);
                result.append(lf);
            }
            int zero;
            for(zero = 0;zero < size - 1;zero++) {
                if(result[zero] != '0') {
                    break;
                }
            }

            return result.substr(zero, result.size() - zero);
        }
};


int main(int argc, char **argv)
{
    Solution sol;
    vector<int> nums = {41,23,87,55,50,53,18,9,39,63,35,33,54,25,26,49,74,61,32,81,97,99,38,96,22,95,35,57,80,80,16,22,17,13,89,11,75,98,57,81,69,8,10,85,13,49,66,94,80,25,13,85,55,12,87,50,28,96,80,43,10,24,88,52,16,92,61,28,26,78,28,28,16,1,56,31,47,85,27,30,85,2,30,51,84,50,3,14,97,9,91,90,63,90,92,89,76,76,67,55};
    string result;

    result = sol.largestNumber(nums);

    cout << result << endl;

    return 0;
}

