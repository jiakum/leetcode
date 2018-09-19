
class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            int max_len = 0, minlen = INT_MAX;
            for (const auto& word: wordDict) {
                max_len = max(max_len, (int)word.size());
                minlen  = min(minlen, (int)word.size());
            }

            map<string, int> dict;
            for(int i = 0;i < wordDict.size();i++) {
                string s = wordDict[i];
                dict[s] = i;
            }

            const int n = s.size();
            vector<int> dp(n + 1, false);
            dp[0] = true;
            for (int i = 0; i <= n - minlen; ++i) {
                int min_j = min(n - i, max_len);
                for (int j = minlen; j <= min_j; j++) {
                    if (dp[i] && (dict.find(s.substr(i, j)) != dict.end())) {
                        dp[i+j] = true;
                        continue;
                    }
                }
            }
            return dp[n];
        }
};
