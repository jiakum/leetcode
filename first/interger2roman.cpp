
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

static unsigned char roman[4][2] = {
    {'I', 'V'},
    {'X', 'L'},
    {'C', 'D'},
    {'M', '\0'},
};

class Solution {
    public:
        string intToRoman(int num) {
            string s;
            vector<string> vs;
            int n, i, ptr = 0;

            if(num > 3999)
                return s;

            while(num) {
                n = num % 10;
                num /= 10;

                switch(n) 
                {
                    case 4:
                        s.push_back(roman[ptr][0]);
                        s.push_back(roman[ptr][1]);
                        break;
                    case 9:
                        s.push_back(roman[ptr][0]);
                        s.push_back(roman[ptr + 1][0]);
                        break;
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                        i = n - 0;
                        while(i--) {
                            s.push_back(roman[ptr][0]);
                        }
                        break;
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        s.push_back(roman[ptr][1]);
                        i = n - 5;
                        while(i--) {
                            s.push_back(roman[ptr][0]);
                        }
                        break;
                }

                ptr++;

                vs.push_back(s);
                s.clear();
            }

            for(i = vs.size() - 1;i >= 0;i--)
                s += vs[i];

            return s;
        }
};

int main()
{
    Solution sol;
    int x = 58;

    cout << sol.intToRoman(x) << endl;

    return 0;
}

