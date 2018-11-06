
class Solution {
    public:
        vector<string> findWords(vector<string>& words) {
            const int alpha_index[26] = {2, 1, 1, 2, 3, 2, 2, 
                /*h*/ 2, 3, 2, 2, 2, 1, 1, 
                /*o*/ 3, 3, 3, 3, 2, 3,
                /*u*/ 3, 1, 3, 1, 3, 1};
            vector<string> result;
            int i, size = words.size();

            for(i = 0;i < size;i++) {
                string &str = words[i];
                char c = tolower(str[0]);
                int j, len = str.size(), index = alpha_index[c- 'a'];

                for(j = 1;j < len;j++) {
                    c = tolower(str[j]);

                    if(index != alpha_index[c - 'a']) {
                        break;
                    }
                }

                if(j == len) {
                    result.push_back(str);
                }
            }

            return result;
        }
};
