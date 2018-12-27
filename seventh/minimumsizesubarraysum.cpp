
class Solution {
    public:
        int minSubArrayLen(int s, vector<int>& nums) {
            int result = INT_MAX, sum = 0, last = 0;

            for(int i = 0;i < nums.size();i++) {
                sum += nums[i];

                while(sum >= s) {
                    result = min(result, i - last + 1);

                    sum -= nums[last++];
                }
            }

            return result == INT_MAX ? 0: result;
        }
};
