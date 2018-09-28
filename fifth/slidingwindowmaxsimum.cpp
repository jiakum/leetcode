
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            map<int, int> lmap;
            map<int, int>::iterator iter;
            vector<int> result;
            int i = 0, size = nums.size();

            if(k > size || k == 0 || size == 0)
                return result;

            for(i = 0;i < k;i++) {
                int n = nums[i];
                iter = lmap.find(n);
                if(iter == lmap.end())
                    lmap[n] = 1;
                else
                    iter->second++;
            }
            result.push_back(lmap.rbegin()->first);

            for(i = k;i < size;i++) {
                int n = nums[i - k];

                iter = lmap.find(n);
                iter->second--;
                if(iter->second <= 0)
                    lmap.erase(iter);

                n = nums[i];
                iter = lmap.find(n);
                if(iter == lmap.end())
                    lmap[n] = 1;
                else
                    iter->second++;

                result.push_back(lmap.rbegin()->first);
            }

            return result;
        }
};
