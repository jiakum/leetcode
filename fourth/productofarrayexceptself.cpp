
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int N = nums.size();
            vector<int> ans(N, 1);
            int left = 1, right = 1;

            /* product of all elements before i */
            for (int i = 1; i < N; ++i) {
                left *= nums[i-1];
                ans[i] = left;
            }

            /* product of all elements after i */
            for (int i = N-2; i >= 0; --i) {
                right *= nums[i+1];
                ans[i] *= right;
            }
            return ans;
        }
};
