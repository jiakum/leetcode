
class Solution {
    public:
        int findLHS(vector<int>& nums) {
            int result = 0, i, size = nums.size();
            vector<int> snum(nums);

            if(size <= 1)
                return 0;

            sort(snum.begin(), snum.end());

            pair<int, int> big(snum[0], 0), lowest = big;
            for(i = 1;i < size;i++) {
                int n = snum[i], len = 0;

                if(n > lowest.first + 1) {
                    if(n > big.first + 1) {
                        big = pair<int, int>(n, i);
                        lowest = big;
                    } else {
                        lowest = big;
                        big = pair<int, int>(n, i);
                    }
                } else {
                    if(n == big.first + 1) {
                        big = pair<int, int>(n, i);                    
                    }
                }

                if(n == lowest.first + 1) {
                    len = i - lowest.second + 1;
                    result = max(len, result);
                }
            }

            return result;
        }
};

class Solution {
    public:
        int findLHS(vector<int>& nums) {
            unordered_map<int, int> hmap;
            unordered_map<int, int>::iterator iter, big;
            int i, size = nums.size(), result = 0;

            if(size <= 1)
                return 0;

            for(i = 0;i < size;i++) {
                int n = nums[i];

                iter = hmap.find(n);
                if(iter != hmap.end())
                    iter->second++;
                else
                    hmap[n] = 1;
            }

            for(iter = hmap.begin();iter != hmap.end();iter++) {
                int n = iter->first;

                big = hmap.find(n + 1);
                if(big != hmap.end()) {
                    result = max(result, iter->second + big->second);
                }
            }

            return result;
        }
};
