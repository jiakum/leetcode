
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int i, j, size = nums.size();

            if(size <= 2)
                return size;

            int len = 0;
            for(i = 0;i < size;) {
                int n = nums[i];
                int t = 0;

                while(i < size && n == nums[i]) {
                    t++;
                    if(t <= 2)
                        nums[len++] = nums[i];
                    i++;
                }

            }

            return len;
        }
};
