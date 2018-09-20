
class Solution {
    public:
        string convertToTitle(int n) {
            string result;

            while(n > 0) {
                char m = n % 26;

                if(m == 0) {
                    m = 'Z';
                    n -= 1;
                } else {
                    m = m - 1 + 'A';
                }

                n /= 26;

                result.push_back(m);
            }

            reverse(result.begin(), result.end());

            return result;
        }
};
