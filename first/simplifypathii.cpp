
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
        string simplifyPath(string path) {
            int i, size = path.size(), ptr = 0;

            if(size == 0)
                return "";

            char result[size + 2];
            for(i = 0;i < size;i++) {
                char name[size + 2], *p = name;

                while(i < size && path[i] == '/')
                    i++;

                while(i < size && path[i] != '/')
                    *p++ = path[i++];

                *p = '\0';

                if(p == name)
                    break;

                printf("name:%s\n", name);
                if(strcmp(name, "..") == 0) {
                    while(ptr > 0 && result[ptr] != '/')
                        ptr--;
                    result[ptr] = '\0';
                } else if(strcmp(name, ".") == 0) {
                    continue;
                } else {
                    /* length of name must be less than sizeof result */
                    ptr += sprintf(result + ptr, "/%s", name);
                }
            }

            if(ptr <= 1) {
                snprintf(result, sizeof(result), "/");
            }

            return result;
        }
};

int main(int argc, char **argv)
{
    Solution sol;
    string path = "/...";

    cout << sol.simplifyPath(path) << endl;
    

    return 0;
}
