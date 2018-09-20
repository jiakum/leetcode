
class Solution {
    public:
        int titleToNumber(string s) {
            int result = 0, i, size = s.size();

            for(i = 0;i < size;i++) {
                int m = s[i] - 'A' + 1;

                result = result * 26 + m;
            }

            return result;
        }
};
