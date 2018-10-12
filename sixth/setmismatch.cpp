
class Solution {
    public:
        vector<int> findErrorNums(vector<int>& nums) {
            vector<int> result;
            int i, size = nums.size();
            char dp[size + 1];

            memset(dp, 0, sizeof(dp));
            for(i = 0;i < size;i++) {
                int n = nums[i];

                if(dp[n])
                    result.push_back(n);
                else
                    dp[n] = 1;
            }
            for(i = 1;i <= size;i++) {
                if(dp[i] == 0) {
                    result.push_back(i);
                    break;
                }
            }

            return result;
        }
};
