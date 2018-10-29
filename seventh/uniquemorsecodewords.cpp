
class Solution {
    public:
        int uniqueMorseRepresentations(vector<string>& words) {
            const char *pattern[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
                ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
                ".--","-..-","-.--","--.."};
            unordered_set<string> lmap;
            int i, size = words.size();

            for(i = 0;i < size;i++) {
                string &word = words[i], str;

                for(int j = 0;j < word.size();j++) {
                    char c = word[j] - 'a';

                    if(c < 0 || c >= 26)
                        return -1;

                    str.append(pattern[c]);
                }

                lmap.insert(str);
            }

            return lmap.size();
        }
};
