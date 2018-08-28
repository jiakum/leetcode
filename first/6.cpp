
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            if(numRows > (int)s.size())
                numRows = s.size();
            vector<string> vs(numRows);
            string result;
            int row, val, index, down = 0;

            if(numRows <= 1)
                return s;

            for(index = 0, row = 0;index < (int)s.size();index++) {
                val = s[index];

                vs[row].push_back(val);

                if(row == 0)
                    down = 1;
                else if(row == numRows - 1)
                    down = 0;

                row += down ? 1: -1;
            }

            for(row = 0; row < numRows;row++)
                result += vs[row];

            return result;
        }
};

int main()
{
    Solution sol;
    string s = "AB";

    cout << sol.convert(s, 1) << endl;

    return 0;
}
