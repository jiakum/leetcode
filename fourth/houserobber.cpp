
class Solution {
    public:
        int rob(vector<int>& nums) {
            int i, size = nums.size();

            if(size == 0)
                return 0;
            else if(size == 1)
                return nums[0];

            int dp[size + 2];
            dp[0] = nums[0];
            dp[1] = max(nums[1], nums[0]);
            for(i = 2;i < size;i++) {
                dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
            }

            return dp[size - 1];
        }
};
