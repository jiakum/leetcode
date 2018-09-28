
class Solution {
    public:
        bool checkPossibility(vector<int>& nums) {
            int i, size = nums.size(), result = 0, last;

            for(i = 1;i < size;i++) {
                if(nums[i - 1] > nums[i]) {
                    result++;
                    if(result == 2)
                        break;

                    last = i;
                }
            }

            if(result == 0)
                return true;
            else if(result > 1)
                return false;
            else if(last <= 1 || last >= size - 1){
                return true;
            } else {
                return (nums[last] >= nums[last - 2]) || (nums[last - 1] < nums[last + 1]);
            }
        }
};
