
class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
            int result = INT_MIN, i, size = nums.size(), total = 0;

            for(i = 0;i < k;i++) {
                total += nums[i];
            }

            result = max(result, total);
            for(i = k;i < size;i++) {
                total += nums[i] - nums[i - k];
                result = max(result, total);  
            }

            return (double)result / k;
        }
};
