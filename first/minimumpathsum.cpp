
class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int n = grid.size();

            if(n == 0)
                return 0;

            int m = grid[0].size();
            if(m == 0)
                return 0;

            int i, j, dp[n][m];

            memset(dp, 0, sizeof(dp));
            for(i = 0;i < n;i++) {
                for(j = 0;j < m;j++) {
                    if (i > 0 && j > 0)
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                    else if(i == 0 && j > 0)
                        dp[i][j] = dp[i][j - 1];
                    else if(j == 0 && i > 0)
                        dp[i][j] = dp[i - 1][j];

                    dp[i][j] += grid[i][j];
                }
            }

            return dp[n - 1][m - 1];
        }
};
