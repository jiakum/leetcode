
class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int n = obstacleGrid.size();
            if(n == 0)
                return 0;

            int m = obstacleGrid[0].size();
            if(m == 0)
                return 0;

            int dp[n][m]{0};


            for(int i = 0; i < n; i++)
            {

                for(int j = 0; j < m; j++)
                {
                    if(obstacleGrid[i][j]) {
                        dp[i][j] = 0;
                    }
                    else if(i == 0)
                    {
                        if(j > 0 && dp[i][j - 1] == 0)
                            dp[i][j] = 0;
                        else
                            dp[i][j] = 1;
                    }
                    else if(j == 0)
                    {
                        if(i > 0 && dp[i - 1][j] == 0)
                            dp[i][j] = 0;
                        else
                            dp[i][j] = 1;
                    }

                    //otherwise 
                    else
                    {
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }

                }

            }


            //return the bottom right path count
            return dp[n-1][m-1];
        }
};
