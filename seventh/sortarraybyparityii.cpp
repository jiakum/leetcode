
class Solution {
    public:
        vector<int> sortArrayByParityII(vector<int>& A) {
            vector<int> result(A);
            int odd, even, size = A.size();

            for(odd = 1, even = 0;odd < size && even < size;odd += 2, even += 2) {
                while((odd < size) && ((result[odd] & 0x01) == 0x01)) {
                    odd += 2;
                }
                while((even < size) && ((result[even] & 0x01) == 0x0)) {
                    even += 2;
                }

                if(odd >= size || even >= size)
                    break;

                int temp = result[odd];
                result[odd] = result[even];
                result[even] = temp;
            }

            return result;
        }
};
