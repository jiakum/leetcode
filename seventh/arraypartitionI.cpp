
class Solution {
    public:
        int arrayPairSum(vector<int>& nums) {
            vector<int> snum(nums);
            int result = 0;

            sort(snum.begin(), snum.end());
            for(int i = 0;i < snum.size();i += 2) {
                result += snum[i];
            }

            return result;
        }
};
