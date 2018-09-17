
class Solution {
    public:
        int numDecodings(string s) {
            int i, size = s.size();

            if(size == 0)
                return size;

            int dp[size + 2];
            if(s[0] == '0') {
                return 0;
            } else if(s[size - 1] == '0'){
                dp[size - 1] = 0;  
            } else {
                dp[size - 1] = 1;              
            }
            dp[size] = 1;          
            for(i = size - 2;i >= 0;i--) {
                if(s[i] == '0')
                    dp[i] = 0;
                else
                    dp[i] = dp[i + 1];
                if(s[i] == '2' && s[i + 1] <= '6') {
                    dp[i] += dp[i +  2];
                } else if(s[i] == '1') {
                    dp[i] += dp[i +  2];                
                }
            }

            return dp[0];
        }
};
