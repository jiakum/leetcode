

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int i, size = nums.size(), ptr = 0;

            for(i = 0;i < size;i++) {
                int ni = nums[i];

                if(i > 0 && ni == nums[i - 1])
                    continue;

                nums[ptr] = ni;
                ptr++;
            }

            for(i = ptr;i < size;i++) {
                nums.pop_back();
            }

            return ptr;
        }
};
