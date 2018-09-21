
class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            vector<int> snum(nums);

            if(nums.size() == 0)
                return false;

            sort(snum.begin(), snum.end());
            for(int i = 0;i < snum.size() - 1;i++) {
                if(snum[i] == snum[i + 1])
                    return true;
            }

            return false;
        }
};
