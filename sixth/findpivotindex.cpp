
class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            int i, size = nums.size();

            if(size <= 1)
                return -1;

            int left = 0, right = 0;
            for(i = 1;i < size;i++) {
                right += nums[i];
            }

            if(left == right)
                return 0;

            for(i = 0;i < size - 1;i++) {
                left += nums[i];
                right -= nums[i + 1];
                if(left == right)
                    return i + 1;
            }

            return -1;
        }
};
