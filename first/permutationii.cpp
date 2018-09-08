
class Solution {
    public:

        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int>> result;
            vector<int> vi, sub(nums);

            sort(sub.begin(), sub.end());
            sub_premute(result, sub, vi);

            return result;
        }

        void sub_premute(vector<vector<int>> &result, vector<int> &nums, vector<int> vi) {
            int i, size = nums.size();

            if(nums.empty()) {
                result.push_back(vi);
                return ;
            }
            for(i = 0;i < size;i++) {
                int value = nums[i];

                if(i > 0 && value == nums[i - 1])
                    continue;

                vector<int> sub(nums);
                sub.erase(sub.begin() + i);

                vi.push_back(value);

                sub_premute(result, sub, vi);

                vi.pop_back();
            }
        }

};
