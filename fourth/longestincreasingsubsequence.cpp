
class Solution {
    vector<int> dp;
    public:
    int subLIS(vector<int>& nums, int index, int last) {
        if(dp[index] != -1)
            return dp[index];

        int i, ret = 0, result = 1;
        for(i = index + 1;i < nums.size();i++) {
            if(nums[i] > last)  {
                ret = subLIS(nums, i, nums[i]);
                result = max(ret + 1, result);
            }
        }
        dp[index] = result;

        return result;
    }
    int lengthOfLIS(vector<int>& nums) {
        int i, size = nums.size(), j, result = 1;

        if(size == 0)
            return 0;

        for(i = 0;i < size;i++) 
            dp.push_back(-1);

        for(i = 0;i < size;i++) {
            result = max(result, subLIS(nums, i, nums[i]));
        }

        return result;
    }
};
