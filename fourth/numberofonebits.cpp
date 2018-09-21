
class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int result = 0;
            for(int i = 0;i < 32;i++) {
                unsigned int bit = 1 << i;

                if(n & bit)
                    result++;
            }

            return result;
        }
};
