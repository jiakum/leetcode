
class Solution {
    public:
        int maximumProduct(vector<int>& nums) {
            vector<int> snum(nums);
            int size = nums.size();

            sort(snum.begin(), snum.end());
            return max(snum[0] * snum[1] * snum[size - 1], snum[size - 3] * snum[size - 2] * snum[size - 1]);
        }
};
