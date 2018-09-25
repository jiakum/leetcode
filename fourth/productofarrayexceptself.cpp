
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int size = nums.size();
            vector<int> result(size, 1);
            int left = 1, right = 1;

            /* product of all elements before i */
            for (int i = 1; i < size; ++i) {
                left *= nums[i-1];
                result[i] = left;
            }

            /* product of all elements after i */
            for (int i = size-2; i >= 0; --i) {
                right *= nums[i+1];
                result[i] *= right;
            }
            return result;
        }
};
