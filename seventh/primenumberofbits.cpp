
class Solution {
    public:
        int count_bit(unsigned int n) {
            int result = 0;

            for(int i = 0;i < 8;i++) {
                if(n & (1 << i))
                    result++;
            }
            if(n < (1 << 8))
                return result;

            for(int i = 8;i < 16;i++) {
                if(n & (1 << i))
                    result++;
            }
            if(n < (1 << 16))
                return result;

            for(int i = 16;i < 24;i++) {
                if(n & (1 << i))
                    result++;
            }
            if(n < (1 << 24))
                return result;

            for(int i = 24;i < 32;i++) {
                if(n & (1 << i))
                    result++;
            }

            return result;
        }
        int countPrimeSetBits(int L, int R) {
            const char prime[32] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0,
                0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
                0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1};
            int result = 0;
            for(int n = L;n <= R;n++) {
                int bits = count_bit(n);

                if(prime[bits])
                    result++;
            }

            return result;
        }
};
