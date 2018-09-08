class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> result;
            vector<int> vi;

            sub_premute(result, nums, vi);

            return result;
        }

        void sub_premute(vector<vector<int>> &result, vector<int> &nums, vector<int> vi) {
            int i, size = nums.size();

            if(nums.empty()) {
                result.push_back(vi);
                return ;
            }
            for(i = 0;i < size;i++) {
                vector<int> sub(nums);

                sub.erase(sub.begin() + i);

                vi.push_back(nums[i]);

                sub_premute(result, sub, vi);

                vi.pop_back();
            }
        }
};
