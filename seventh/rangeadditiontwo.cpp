
class Solution {
    public:
        int maxCount(int m, int n, vector<vector<int>>& ops) {
            for(int i = 0;i < ops.size();i++) {
                vector<int> &vi = ops[i];

                m = min(m, vi[0]);
                n = min(n, vi[1]);
            }

            return m * n;
        }
};
