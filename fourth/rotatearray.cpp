
class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int size = nums.size();
            if(size == 0)
                return;

            k %= size;
            if(k == 0)
                return;

            vector<int> back(nums);
            for(int i = 0;i < size;i++) {
                int index = size - k + i;
                if(index >= size)
                    index -= size;
                nums[i] = back[index];
            }
        }
};
