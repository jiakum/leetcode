
class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            int i = 0, size = nums.size();
            set<int> iset;

            for(i = 0;i < size;i++) {
                int n = nums[i];
                if(iset.find(n) != iset.end())
                    return true;
                else {
                    iset.insert(n);
                    if(iset.size() > k)
                        iset.erase(nums[i - k]);
                }
            }

            return false;
        }
};
