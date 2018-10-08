
class Solution {
    public:
        bool isPerfectSquare(int num) {
            unsigned int left = num, right = 1;

            if(num < 0)
                return false;
            else if(num <= 1)
                return true;

            if(left > 0x0ffff)
                left = 0xffff;

            while(left >= right) {
                int mid = (left + right) / 2;

                if(num / mid == mid) {
                    return num % mid == 0;
                } else if(num / mid > mid) {
                    right = mid + 1;
                } else {
                    left = mid - 1;
                }
            }

            return false;
        }
};
