
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int size = prices.size();

            if(size <= 1)
                return 0;

            int dp[size], i, left = prices[0], result = 0;
            for(i = 1;i < size;i++) {
                int p = prices[i];
                int num = p - left;

                if(num > 0) {
                    dp[i] = num;
                    left = p;
                } else { 
                    if(p < left) 
                        left = p;
                    dp[i] = 0;
                }

                result += dp[i];
            }

            return result;
        }
};
