
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
        bool isValid(string s) {
            int size = s.size(), ptr = 1;
            char flag[size + 2];

            if(size == 0)
                return true;
            else if(size & 0x01)
                return false;

            for(int i = 0;i < size;i++) {
                char c = s[i];
                switch(c)
                {
                    case '(':
                    case '{':
                    case '[':
                        flag[ptr] = c;
                        ptr++;
                        break;
                    case '}':
                        ptr--;
                        if(flag[ptr] != '{')
                            return false;
                        break;
                    case ')':
                        ptr--;
                        if(flag[ptr] != '(')
                            return false;
                        break;
                    case ']':
                        ptr--;
                        if(flag[ptr] != '[')
                            return false;
                        break;
                    default:
                        return false;
                }
            }

            return ptr == 1 ? true : false;
        }
};

int main(int argc, char **argv)
{
    Solution sol;

    

    return 0;
}
