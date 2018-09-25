
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int zero = 0, ptr = 0, i;
            for(i = 0;i < nums.size();i++) {
                if(nums[i] == 0)
                    zero++;
                else {
                    nums[ptr] = nums[i];
                    ptr++;
                }
            }

            for(i = nums.size() - zero;i < nums.size();i++) {
                nums[i] = 0;
            }
        }
};
