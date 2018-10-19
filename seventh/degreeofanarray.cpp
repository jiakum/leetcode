
class Solution {
    public:
        int findShortestSubArray(vector<int>& nums) {
            map<int, pair<int, pair<int, int>>> lmap;
            map<int, pair<int, pair<int, int>>>::iterator iter;
            int i, size = nums.size();

            for(i = 0;i < size;i++) {
                int n = nums[i];

                iter = lmap.find(n);
                if(iter != lmap.end()) {
                    pair<int, int> pi = iter->second.second;
                    pi.second = i;

                    pair<int, pair<int, int>> ppi(iter->second.first + 1, pi);

                    iter->second = ppi;
                } else {
                    pair<int, int> pi = pair<int, int>(i, i);
                    pair<int, pair<int, int>> ppi(1, pi);

                    lmap[n] = ppi;
                }
            }

            pair<int, int> result(0, size);
            for(iter = lmap.begin();iter != lmap.end();iter++) {
                pair<int, int> pi = iter->second.second;

                if(iter->second.first > result.first) {
                    result.first = iter->second.first;
                    result.second = pi.second - pi.first + 1;
                } else if(iter->second.first == result.first && result.second > pi.second - pi.first + 1) {
                    result.second = pi.second - pi.first + 1;
                }
            }

            return result.second;
        }
};
