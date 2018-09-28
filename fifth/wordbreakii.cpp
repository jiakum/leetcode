
class Solution {
    public:
        void addSub(vector<vector<string>> &dp, int index, 
                vector<string> &word, vector<string> &result) {
            if(index == 0) {
                string str;
                for(int i = word.size() - 1;i >= 0;i--) {
                    str.append(word[i]);
                    str.push_back(' ');
                }
                str.pop_back();
                result.push_back(str);
                return;
            }

            //printf("index:%d, word:%s\n", index, word.c_str());
            vector<string> &vs = dp[index];
            int len = word.size();
            for(int i = 0;i < vs.size();i++) {
                string &str = vs[i];

                word.push_back(str);
                addSub(dp, index - str.size(), word, result);
                word.pop_back();
            }
        }
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            int max_len = 0, minlen = INT_MAX;
            map<string, int> dict;

            for(int i = 0;i < wordDict.size();i++) {
                string s = wordDict[i];
                dict[s] = i;
                max_len = max(max_len, (int)s.size());
                minlen  = min(minlen, (int)s.size());
            }

            const int n = s.size();
            vector<string> result, vs;
            vector<vector<string>> dp(n + 2, vs);
            vs.push_back(" ");
            dp[0] = vs;

            for (int i = 0; i <= n - minlen; ++i) {
                int min_j = min(n - i, max_len);
                for (int j = minlen; j <= min_j; j++) {
                    string sub = s.substr(i, j);
                    if (!dp[i].empty() && (dict.find(sub) != dict.end())) {
                        dp[i+j].push_back(sub);
                        continue;
                    }
                }
            }

            vs = dp[n];
            for(int i = 0;i < vs.size();i++) {
                vector<string> word;
                string &str = vs[i];

                word.push_back(str);
                addSub(dp, n - str.size(), word, result);
                word.clear();
                cout << str << endl;
            }
            return result;
        }
};
