
class Solution {
    public:
        string addStrings(string num1, string num2) {
            int i, j, size1 = num1.size(), size2 = num2.size(), plus = 0;
            string result;

            for(i = size1 - 1, j = size2 - 1;(i >= 0) || (j >= 0);) {
                char c = plus;

                if(i >= 0) {
                    c += num1[i] - '0';
                    i--;
                }
                if(j >= 0) {
                    c += num2[j] - '0';
                    j--;
                }

                if(c >= 10) {
                    c -= 10;
                    plus = 1;
                } else {
                    plus = 0;
                }

                c += '0';
                result.push_back(c);
            }

            if(plus)
                result.push_back('1');

            reverse(result.begin(), result.end());
            return result;
        }
};
