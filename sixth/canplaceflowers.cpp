
class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
            int result = 0, i, size = flowerbed.size(), zero = 1;

            for(i = 0;i < size;i++) {
                int n = flowerbed[i];
                if(n == 0) {
                    zero ++;
                } else {
                    zero = (zero + 1) / 2 - 1;
                    if(zero > 0)
                        result += zero;
                    zero = 0;
                }
            }
            zero = zero / 2;
            if(zero > 0)
                result += zero;

            return result >= n;
        }
};
