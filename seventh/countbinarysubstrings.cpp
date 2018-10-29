
class Solution {
    public:
        int countBinarySubstrings(string s) {
            int i, size = s.size(), zero, one, last, result = 0;

            last = s[0] == '0' ? 0 : 1;
            one  = s[0] == '0' ? 0 : 1;
            zero  = s[0] == '0' ? 1 : 0;
            for(i = 1;i < size;i++) {
                int n = s[i] == '0' ? 0: 1;
                if(last != n) {
                    result++;

                    if(n == 1) {
                        one = 1;
                    } else{
                        zero = 1;
                    }
                } else {
                    if(n == 1) {
                        one++;
                        if(zero >= one)
                            result++;
                    } else {
                        zero++;
                        if(zero <= one)
                            result++;
                    }

                }

                last = n;
            }

            return result;
        }
};
