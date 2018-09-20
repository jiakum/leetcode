
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            map<int, int> imap;
            map<int, int>::iterator iter;
            int i, size = nums.size();

            if(size == 0)
                return 0;

            for(i = 0;i < size;i++) {
                int n = nums[i];
                iter = imap.find(n);

                if(iter != imap.end()) {
                    iter->second += 1;
                    if(iter->second >= (size + 1) / 2)
                        return n;
                } else {
                    imap[n] = 1;
                }
            }

            return nums[0];
        }
};
