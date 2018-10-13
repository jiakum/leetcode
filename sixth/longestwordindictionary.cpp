
class Solution {
    public:
        string longestWord(vector<string>& words) {
            unordered_set<string> wordset;
            string ans;

            for (string word: words) wordset.insert(word);

            for (string word: words) {
                if (word.size() > ans.size() ||
                        (word.size() == ans.size() && word.compare(ans) < 0)) {
                    bool good = true;
                    for (int k = 1; k < word.size(); ++k) {
                        if (wordset.find(word.substr(0, k)) == wordset.end()) {
                            good = false;
                            break;
                        }
                    }
                    if (good) ans = word;
                }    
            }

            return ans;
        }
};
