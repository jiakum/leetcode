
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int size = nums.size(), i;

            if(size <= 1)
                return true;

            int dp[size];

            for(i = 0;i < size - 1;i++) {
                if(i > 0)
                    dp[i] = max(dp[i - 1] - 1, nums[i]);
                else
                    dp[0] = nums[0];

                if(dp[i] == 0)
                    return false;
            }

            return true;
        }
};
