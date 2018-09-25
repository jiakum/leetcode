
class Solution {
    public:
        int longestSubstring(string s, int k) {
            int result = 0;
            queue<string> q;
            q.push(s);
            while (!q.empty()) {
                string str = q.front();
                q.pop();
                int N = str.length();
                if (N <= result) {
                    continue;
                }
                int i = 0;
                bool valid = true;
                int freq[26] = {0};
                while (i < N) {
                    freq[str[i]-'a']++;
                    i++;
                }
                i = 0;
                while (i < N) {
                    if (freq[str[i]-'a'] < k) {
                        str[i] = '\0';
                        valid = false;
                    }
                    i++;
                }
                if (valid) {
                    result = max(result, N);
                    continue;
                }
                i = 0;
                while (i < N) {
                    if (str[i] != '\0') {
                        string sect(&str[i]);
                        q.push(sect);
                        i += sect.length();
                    }
                    else {
                        i++;
                    }
                }
            }
            return result;
        }
};
