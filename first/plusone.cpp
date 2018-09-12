
class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            vector<int> result(digits);
            int i, size = result.size(), plus = 1;

            for(i = size - 1;i >= 0;i--) {
                int num = result[i] + plus;

                if(num >= 10) {
                    plus = 1;
                    num -= 10;
                } else {
                    plus = 0;
                }

                result[i] = num;
            }

            if(plus)
                result.insert(result.begin() + 0, plus);

            return result;
        }
};
