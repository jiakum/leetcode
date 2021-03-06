
class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int i, size = nums.size();

            if(size < 2)
                return 0;

            if(nums[0] > nums[1])
                return 0;

            for(i = 1;i < size -1;i++) {
                if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                    return i;
            }

            if(nums[size - 1] > nums[size - 2])
                return size - 1;

            return 0;
        }
};
