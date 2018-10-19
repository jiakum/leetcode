
class Solution {
    public:
        vector<string> findRelativeRanks(vector<int>& nums) {
            vector<int> snum(nums);
            int i, size = nums.size();
            unordered_map<int, int> lmap(size + 2);
            unordered_map<int, int>::iterator iter;

            sort(snum.begin(), snum.end());
            for(i = 0;i < size;i++) {
                int n = snum[i];

                lmap[n] = size - i;
            }

            vector<string> result;
            char str[16];
            for(i = 0;i < size;i++) {
                int n = nums[i];

                iter = lmap.find(n);
                switch(iter->second)
                {
                    case 1:
                        result.push_back(string("Gold Medal"));
                        break;
                    case 2:
                        result.push_back(string("Silver Medal"));
                        break;
                    case 3:
                        result.push_back(string("Bronze Medal"));
                        break;
                    default:
                        snprintf(str, sizeof(str), "%d", iter->second);
                        result.push_back(string(str));
                        break;
                }
            }

            return result;
        }
};
