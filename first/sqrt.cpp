
class Solution {
    public:
        int mySqrt(int x) {
            int left = x, right = 0;
            unsigned div = 0;

            if(x <= 1)
                return x;

            if(left > (1 << 16))
                left = 1 << 16;
            while(left >= right) {
                unsigned int num = (left + right) >> 1;
                div = x / num;

                if(div == num)
                    return num;
                else if(div < num)
                    left = num - 1;
                else
                    right = num + 1;
            }

            return (right + left) >> 1;
        }
};
