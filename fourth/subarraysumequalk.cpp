
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int,int> lmap;
            unordered_map<int,int>::iterator iter;

            lmap[0] = 1;
            int total = 0, result = 0;
            for(int i = 0;i < nums.size();i++) {
                total += nums[i];
                iter = lmap.find(total - k);
                if(iter != lmap.end()) {
                    result += iter->second;
                }
                iter = lmap.find(total);
                if(iter == lmap.end()) {
                    lmap[total] = 1;
                } else {
                    iter->second++;
                }
            }

            return result;
        }
};
