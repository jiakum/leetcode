
class Solution {
    public:
        static bool compare(pair<int,int> &left, pair<int,int> &right) {
            return left.second > right.second;
        }
        vector<int> topKFrequent(vector<int>& nums, int k) {
            map<int,int> lmap;
            map<int,int>::iterator iter;
            int i, size = nums.size();

            for(i = 0;i < size;i++) {
                int n = nums[i];
                iter = lmap.find(n);
                if(iter == lmap.end())
                    lmap[n] = 1;
                else
                    lmap[n]++;
            }

            vector<pair<int,int>> vp(lmap.begin(), lmap.end());
            sort(vp.begin(), vp.end(), compare);

            vector<int> result;
            for(i = 0;i < k;i++) {
                result.push_back(vp[i].first);
            }

            return result;
        }
};
