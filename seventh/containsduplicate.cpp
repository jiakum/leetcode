

class Solution {
    bool inrange(int k, int n, int t) {
        long lk = k, ln = n, lt = t;

        if(lk < ln)
            return ln - lk <= t;
        else
            return lk - ln <= t;
    }
    public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> lmap;
        set<int>::iterator iter;
        int i, j, size = nums.size(), n, lb, ub;

        if(size <= 1 || t < 0 || k <= 0)
            return false;


        for(i = 0;i < size;i++) {
            n = nums[i];

            iter = lmap.lower_bound(n);
            if(iter == lmap.end()) {
                set<int>::reverse_iterator riter = lmap.rbegin();

                if(riter != lmap.rend() && inrange(*riter, n, t))
                    return true;
            }  else {
                if(inrange(*iter, n, t))
                    return true;

                iter--;
                if((iter != lmap.end()) && inrange(*iter, n, t))
                    return true;
            }

            lmap.insert(n);
            if(lmap.size() == k + 1)
                lmap.erase(nums[i - k]);
        }

        return false;
    }
};
