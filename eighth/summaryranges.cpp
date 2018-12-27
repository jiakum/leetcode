
class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            set<int> data;
            int i, size = nums.size();
            vector<string> result;

            for(i = 0;i < size;i++) {
                char str[64];
                int start = i;

                while(i + 1 < size && nums[i + 1] == nums[i] + 1 ) {
                    i++;
                }

                int end = i;
                if(start == end) {
                    snprintf(str, sizeof(str), "%d", nums[start]);
                } else {
                    snprintf(str, sizeof(str), "%d->%d", nums[start], nums[end]);                
                }

                result.push_back(string(str));
            }

            return result;
        }
};
