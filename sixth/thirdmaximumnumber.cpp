
class Solution {
    public:
        int thirdMax(vector<int>& nums) {
            set<int> iset;

            for(int i = 0;i < nums.size();i++) {
                int n = nums[i];

                if(iset.size() == 3 && n > *iset.begin()) {
                    iset.insert(n);
                    if(iset.size() == 4)
                        iset.erase(iset.begin());
                } else if(iset.size() < 3) {
                    iset.insert(n);
                }
            }

            return iset.size() == 3 ? *iset.begin():*iset.rbegin();
        }
};
