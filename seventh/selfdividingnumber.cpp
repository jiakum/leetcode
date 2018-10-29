
class Solution {
    public:
        vector<int> selfDividingNumbers(int left, int right) {
            vector<int> result;
            int n;

            for(;left <= right;left++) {
                char num[16];
                int size;
                bool selfd = true;

                size = snprintf(num, sizeof(num), "%d", left);
                for(int i = 0;i < size;i++) {
                    char c = num[i] - '0';
                    if(c == 0 || left % c != 0) {
                        selfd = false;
                        break;
                    }
                }

                if(selfd)
                    result.push_back(left);
            }

            return result;
        }
};
