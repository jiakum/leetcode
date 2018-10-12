
class Solution {
    public:
        int dominantIndex(vector<int>& nums) {
            map<int, int> imap;
            map<int, int>::iterator iter;
            int i, size = nums.size();

            if(size < 1)
                return -1;

            for(i = 0;i < size;i++) {
                int n = nums[i];

                iter = imap.find(n);
                if(iter != imap.end())
                    continue;

                imap[n] = i;

                if(imap.size() > 2)
                    imap.erase(imap.begin());
            }

            if(imap.size() == 1)
                return 0;
            else {
                iter = imap.begin();
                int second = iter->first;
                iter++;
                int first = iter->first;
                return (second << 1 <= first) ? iter->second: -1;
            }
        }
};
