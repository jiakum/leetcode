
class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> result;
            int i;

            result.push_back(0);
            if(n == 0)
                return result;

            result.push_back(1);
            for(i = 1;i < n;i++) {
                int pos = result.size() - 1;

                while(pos >= 0) {
                    result.push_back(result[pos--] | (1 << i));
                }
            }

            return result;
        }
};
