
class Solution {
    public:
        void wiggleSort(vector<int>& nums) {
            vector<int> snum(nums);
            int i, size = nums.size();
            sort(snum.begin(), snum.end());

            for(i = 0;i < size;i += 2) {
                nums[i] = snum[(size - i - 1) / 2];
                //printf("i:%d,num:%d\n", i, nums[i]);
            }
            for(i = 1;i < size;i += 2) {
                nums[i] = snum[size / 2 + (size - i) / 2];
                //printf("i:%d,num:%d\n", i, nums[i]);
            }
        }
};
