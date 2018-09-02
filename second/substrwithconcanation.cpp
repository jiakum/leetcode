
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

class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            vector<int> result;
            int n = words.size(), size = s.size(), start = 0, end = size;
            int pos, i, j, last = -1;
            const char *buf = s.c_str();

            if(n == 0)
                return result;

            int len = words[0].size();
            if(len == 0 || size < n * len)
                return result;

            char found[n];
            int success = 0;
            memset(found, 0, sizeof(found));
            for(i = 0;i < size;i++) {
                const char *ptr = strstr(buf + i, words[0].c_str());

                printf("i:%d\n", i);
                if(ptr == NULL)
                    break;

                memset(found, 0, sizeof(found));
                found[0] = 1;
                success = 1;

                pos = ptr - buf;
                start = pos;

                printf("%s,%d, str:%s, ptr:%s success:%d, i:%d, pos:%d,start:%d\n", __func__, __LINE__, buf, ptr, success, i, pos, start);
                while(pos - last > len) {
                    for(j = 1;j < n;j++) {
                        if(success == n)
                            break;

                        if(found[j])
                            continue;

                        if(strncmp(buf + pos - len, words[j].c_str(), len) == 0) {
                            found[j] = 1;
                            success++;
                            pos -= len;
                            start = pos;
                            break;
                        }
                    }

                    if(j == n || success == n) /* no string match */
                        break;
                }

                pos = ptr - buf + len;
                printf("%s,%d, str:%s, success:%d, i:%d, pos:%d,start:%d, last:%d\n"
                        , __func__, __LINE__, buf, success, i, pos, start, last);
                while(end - pos >= len) {
                    for(j = 1;j < n;j++) {
                        if(success == n)
                            break;

                        if(found[j])
                            continue;

                        if(strncmp(buf + pos, words[j].c_str(), len) == 0) {
                            found[j] = 1;
                            success++;
                            pos += len;
                            break;
                        }
                    }

                    if(j == n || success == n) /* no string match */
                        break;
                }

                if(success == n && start > last) {
                    result.push_back(start);

                    i = last;
                    last = start;
                    printf("found one :%d\n", start);
                } else {

                    i = ptr - buf;
                }
            }

            return result;
        }
};

int main(int argc, char **argv)
{
    vector<int> result;
    Solution sol;
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar","foo","the"};
    int i;

    result = sol.findSubstring(s, words);
    for(i = 0;i < (int)result.size();i++) {
        printf("%d\n", result[i]);
    }
    

    return 0;
}
