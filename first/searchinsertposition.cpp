class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int size = nums.size(), i, j, half;

            if(size == 0)
                return 0;
            else if(size == 1) {
                if(nums[0] >= target)
                    return 0;
                else 
                    return 1;
            }

            i = 0;j = size - 1;

            while(i + 1 < j && nums[i] != target && nums[j] != target) {
                half = (i + j) / 2;

                if(nums[half] > target)
                    j = half;
                else if(nums[half] < target)
                    i = half;
                else
                    return half;

                printf("i:%d,j:%d\n", i, j);
            }

            if(nums[i] == target)
                return i;
            else if(nums[j] == target)
                return j;
            else  {
                if(nums[j] < target)
                    return j + 1;
                else if(nums[i] > target)
                    return i;
                else
                    return j;
            }
        }
};
