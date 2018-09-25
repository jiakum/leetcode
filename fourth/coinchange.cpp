
class Solution {
    public:
        int ccdp(vector<int>& coins, int rem, vector<int>& count) {
            if (rem < 0) return -1;
            if (rem == 0) return 0;
            if (count[rem - 1] != 0) return count[rem - 1];
            int min = INT_MAX;
            for (int coin : coins) {
                int res = ccdp(coins, rem - coin, count);
                if (res >= 0 && res < min)
                    min = 1 + res;
            }
            count[rem - 1] = (min == INT_MAX) ? -1 : min;
            return count[rem - 1];
        }
        int coinChange(vector<int>& coins, int amount) {
            vector<int> snum(coins), count(amount, 0);

            sort(snum.begin(), snum.end());
            return ccdp(snum, amount, count);
        }
};
