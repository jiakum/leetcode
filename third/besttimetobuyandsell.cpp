
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int size = prices.size();

            if(size <= 1)
                return 0;

            int i = 0, j = size - 1;
            int left = prices[i], right = 0;

            for(i = 1;i < prices.size();i++) {
                if(prices[i] < left) {
                    left = prices[i];
                }
                if(prices[i] - left > right)
                    right = prices[i] - left;
            }

            return right;
        }
};
