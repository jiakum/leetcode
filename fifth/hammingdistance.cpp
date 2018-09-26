
class Solution {
    public:
        int hammingDistance(int x, int y) {
            int result = 0, i;

            for(i = 0;i < 32;i++) {
                int bit = 1 << i;

                if((x & bit) != (y & bit))
                    result ++;
            }

            return result;
        }
};
