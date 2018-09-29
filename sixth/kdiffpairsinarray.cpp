
class Solution {
    public:
        int findPairs(vector<int>& nums, int k) {
            map<int, int> lmap;
            map<int, int>::iterator iter;

            if(k < 0)
                return 0;

            for(int i = 0;i < nums.size();i++) {
                int n = nums[i];

                iter = lmap.find(n);
                if(iter == lmap.end())
                    lmap[n] = 1;
                else
                    iter->second++;
            }

            int result = 0;
            for(iter = lmap.begin();iter !=lmap.end();iter++) {
                int n = iter->first;

                if(k != 0) {
                    if(lmap.find(n + k) != lmap.end())
                        result++;
                } else if(iter->second > 1) {
                    result += 1;
                }
            }

            return result;
        }
};
