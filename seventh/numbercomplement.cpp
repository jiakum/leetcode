
class Solution {
    public:
#ifndef BITS_PER_LONG
#define BITS_PER_LONG (64)
#endif
        int getFLS(unsigned long word) {
            int num = BITS_PER_LONG - 1;

#if BITS_PER_LONG == 64
            if (!(word & (~0ul << 32))) {
                num -= 32;
                word <<= 32;
            }
#endif
            if (!(word & (~0ul << (BITS_PER_LONG-16)))) {
                num -= 16;
                word <<= 16;
            }
            if (!(word & (~0ul << (BITS_PER_LONG-8)))) {
                num -= 8;
                word <<= 8;
            }
            if (!(word & (~0ul << (BITS_PER_LONG-4)))) {
                num -= 4;
                word <<= 4;
            }
            if (!(word & (~0ul << (BITS_PER_LONG-2)))) {
                num -= 2;
                word <<= 2;
            }
            if (!(word & (~0ul << (BITS_PER_LONG-1))))
                num -= 1;
            return num;


        }
        int findComplement(int num) {
            unsigned int x = num;
            int bit = getFLS(x);
            unsigned int mask = (1 << bit) - 1;

            return (int)((~x) & mask);
        }
};
