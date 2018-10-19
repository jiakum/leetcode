
class Solution {
    public:
        int numberOfBoomerangs(vector<pair<int, int>>& points) {
            int i, size = points.size();

            if(size < 3)
                return 0;

            int j, result = 0;
            int dp[size][size];
            unordered_map<int, int> lmap(size);
            unordered_map<int, int>::iterator iter;
            for(i = 0;i < size;i++) {
                pair<int, int> &pi = points[i];
                int n;

                for(j = 0;j < size;j++) {
                    if(i < j) {
                        pair<int, int> &pj = points[j];
                        n = (pj.first - pi.first) * (pj.first - pi.first)
                            + (pj.second - pi.second) * (pj.second - pi.second);
                    } else if(i > j) {
                        n = dp[j][i];
                    } else {
                        continue;
                    }

                    iter = lmap.find(n);
                    if(iter == lmap.end())
                        lmap[n] = 1;
                    else
                        iter->second++;

                    dp[i][j] = n;
                }
                for(iter = lmap.begin();iter != lmap.end();iter++) {
                    int n = iter->second;

                    if(n <= 1)
                        continue;

                    n = (n - 1) * n;
                    result += n;
                }
                lmap.clear();

            }

            return result;
        }
};
