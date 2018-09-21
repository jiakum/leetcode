
class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            unsigned int result = 0;
            for(int i =0;i < 32;i++) {
                unsigned int bit = n & (1 << i);

                result |= (bit >> i) << (31 - i);
            }

            return result;
        }
};
