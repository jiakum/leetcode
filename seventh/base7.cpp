
class Solution {
    public:
        string convertToBase7(int num) {
            string str;
            int flag = 1;

            if(num < 0) {
                flag = -1;
                num  = -num;
            }

            while(num > 0) {
                int n = num % 7;

                num /= 7;
                str.push_back('0' + n);
            }

            if(str.empty())
                str.push_back('0');
            if(flag == -1)
                str.push_back('-');

            reverse(str.begin(), str.end());

            return str;
        }
};
