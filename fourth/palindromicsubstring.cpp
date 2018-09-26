
class Solution {
    public:
        int countSubstrings(string s) {
            int i, size = s.size(), j, result = 0;
            if(size == 0)
                return result;

            short dp[size + 2][size + 2];
            for(i = 0;i <= size;i++) 
                for(j = 0;j <= 1;j++) 
                    dp[i][j] = 1;

            result += size;
            for(j = 2;j <= size;j++) {
                for(i = 0;i <= size - j;i++) {
                    if(s[i] == s[i + j - 1] && dp[i + 1][j - 2]) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 0;
                    }

                    result += dp[i][j];
                }
            }

            return result;
        }
};
