
class Solution {
    public:
        int mySqrt(int x) {
            int left = x, right = 0;
            unsigned mul = 0;

            if(x <= 1)
                return x;

            if(left > (1 << 16))
                left = 1 << 16;
            while(left > right + 1) {
                unsigned int num = (left + right) >> 1;
                mul = num * num;

                if(mul == x)
                    return num;
                else if(mul > x)
                    left = num;
                else
                    right = num;
            }

            return (right + left) >> 1;
        }
};
