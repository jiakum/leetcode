
class Solution {
    public:
        string addBinary(string a, string b) {
            string result;
            int i = a.size() - 1, j = b.size() - 1;
            int plus = 0;

            while(i >= 0 || j >= 0) {
                char na = i < 0 ? 0 : a[i] - '0';
                char nb = j < 0 ? 0 : b[j] - '0';

                char num = na + nb + plus;

                if(num >= 2) {
                    num -= 2;
                    plus = 1;
                } else {
                    plus = 0;
                }

                result.push_back(num + '0');
                i--;
                j--;
            }

            if(plus)
                result.push_back('1');

            reverse(result.begin(), result.end());

            return result;
        }
};
