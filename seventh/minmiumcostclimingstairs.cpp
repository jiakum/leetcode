
class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int i, size = cost.size();
            int dp[size + 2];

            dp[0] = cost[0];
            dp[1] = cost[1];

            for(i = 2;i < size;i++) {
                dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
            }

            return min(dp[size - 1], dp[size - 2]);
        }
};
