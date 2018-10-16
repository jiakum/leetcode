
class Solution {
    public:
        int findLengthOfLCIS(vector<int>& nums) {
            int result = 0, i, size = nums.size(), len = 1;

            if(size <= 1)
                return size;

            for(i = 1;i < size;i++) {
                if(nums[i] > nums[i - 1])
                    len++;
                else
                    len = 1;
                result = max(result, len);
            }

            return result;
        }
};
