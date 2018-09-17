
class Solution {
    public:
        void insertSubsets(vector<vector<int>> &result, vector<int>& nums, 
                int n, int start, vector<int> &vi) {
            int i;

            if(n == 0) {
                result.push_back(vi);
                return;
            }

            for(i = start + 1;i < nums.size();i++) {
                int val = nums[i];
                vi.push_back(nums[i]);
                insertSubsets(result, nums, n - 1, i, vi);
                vi.pop_back();

                while(i + 1 < nums.size() && nums[i+1] == val) i++;
            }
        }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> result;
            vector<int> sortnums(nums);
            int i, j, size = nums.size();

            if(size == 0)
                return result;

            sort(sortnums.begin(), sortnums.end());
            for(i = 0;i <= size;i++) {
                vector<int> vi;

                insertSubsets(result, sortnums, i, -1, vi);
            }

            return result;
        }
};
