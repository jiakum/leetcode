
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int left, right, size = nums.size(), tmp;

            for(left = 0, right = size - 1;left < right;) {
                while(nums[left] == 0) left++;

                while(right > left && nums[right] != 0) right--;

                if(left >= right)
                    break;

                tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }        
            for(right = size - 1;left < right;) {
                while(right > left && nums[left] != 2) left++;

                while(right > left && nums[right] == 2) right--;

                if(left >= right)
                    break;

                tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }
};
