
class Solution {
    public:
        int findMin(vector<int>& nums) {
            int i, size = nums.size(), result;

            if(size == 0)
                return 0;

            int left = 0, right = size - 1;

            while(left < right) {
                int mid = (left + right) / 2;

                //printf("left:%d, right:%d, mid:%d\n", left, right, mid);
                if(nums[left] > nums[right]) {
                    if(nums[mid] < nums[right]) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                } else {
                    right = left;
                    break;
                }
            }

            return nums[right];
        }
};
