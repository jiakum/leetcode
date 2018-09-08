
class Solution {
    public:
        double myPow(double x, int n) {
            int flag, i;
            double result = 1.0, pown[32];

            if(n == 0) {
                return result;
            } else if(n < 0) {
                flag = -1;
                n = -n;
            } else {
                flag = 1;
            }

            pown[0] = x;
            for(i = 1;i < 32;i++) {
                pown[i] = pown[i - 1] * pown[i - 1];
            }

            for(i = 0;i < 32;i++) {
                if(n & (0x01 << i)) {
                    result *= pown[i];
                }
            }

            return flag == -1 ? (double)1.0 / result:result;
        }
};
