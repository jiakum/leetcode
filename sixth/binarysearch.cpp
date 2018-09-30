
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1;

            while(left <= right) {
                int mid = (left + right) >> 1;
                int n = nums[mid];

                if(target == n)
                    return mid;
                else if(target < n)
                    right = mid - 1;
                else
                    left = mid + 1;
            }

            return -1;
        }
};
