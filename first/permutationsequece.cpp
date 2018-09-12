
class Solution {
    public:
        string getPermutation(int n, int k) {
            string result(n, '0');
            int i,j, dp[n + 2];
            vector<int> nums(n + 1, 0);

            dp[1] = 1; 
            nums[1] = 1;
            for(i = 2;i < n + 1;i++) {
                dp[i] = i * dp[i - 1];
                nums[i] = i;
            }

            for(i = n;i >= 1;i--) {
                j = 1;
                while(k > dp[i - 1]) {
                    k -= dp[i - 1];
                    j++;
                }

                printf("j:%d\n", j);
                result[n - i] = nums[j] + '0';
                nums.erase(nums.begin() + j);
            }

            return result;
        }
};
