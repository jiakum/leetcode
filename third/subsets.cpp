
class Solution {
    public:
        void subcombine(vector<vector<int>> &result, vector<int> &vi, 
                vector<int>& nums, int s, int n, int k)
        {
            int i;

            if(k == 0) {
                result.push_back(vi);
                return;
            }

            for(i = s + 1;i < n;i++) {
                vi.push_back(nums[i]);
                subcombine(result, vi, nums, i, n, k - 1);
                vi.pop_back();
            } 
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> result;
            vector<int> vi;

            for(int i = 0;i <= nums.size();i++) {
                subcombine(result, vi, nums, -1, nums.size(), i);
            }

            return result;
        }
};
