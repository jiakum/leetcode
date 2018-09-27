
class Solution {
    public:
        static bool compare(int left, int right) {
            return left > right;
        }
        bool subPart(vector<int>& nums, int index, int sum) {
            if(index == nums.size())
                return false;
            else if(nums[index] == sum)
                return true;
            else if(sum < nums[index])
                return false;

            return subPart(nums, index + 1, sum - nums[index]) || subPart(nums, index + 1, sum);
        }
        bool canPartition(vector<int>& nums) {
            int total = 0;

            for(int i = 0;i < nums.size();i++)
                total += nums[i];

            if(total & 0x01)
                return false;

            sort(nums.begin(), nums.end(), compare);

            return subPart(nums, 0, total >> 1);
        }
};
