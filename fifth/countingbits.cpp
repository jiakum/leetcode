
class Solution {
    public:
        vector<int> countBits(int num) {
            vector<int> result;
            int bits[num + 1];

            bits[0] = 0;
            result.push_back(bits[0]);
            for(int i = 1;i <= num;i++) {
                bits[i]= (i & 0x01) + bits[i >> 1];
                result.push_back(bits[i]);
            }

            return result;
        }
};
