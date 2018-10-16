
class Solution {
    public:
        string mostCommonWord(string paragraph, vector<string>& banned) {
            map<string, int> lmap;
            set<string> bset;
            map<string, int>::iterator iter;
            int i, size = paragraph.size(), j, maxfreq = 0;
            string bstr, result;
            char c;

            for(i = 0;i < banned.size();i++) {
                string &ban = banned[i];
                string str;
                for(j = 0;j < ban.size();j++) {
                    c = tolower(ban[j]);
                    str.push_back(c);
                }

                bset.insert(str);
            }

            for(i = 0;i < size;i++) {
                string str;
                while(isalpha(paragraph[i])) {
                    str.push_back(tolower(paragraph[i]));
                    i++;
                }

                if(bset.find(str) != bset.end() || str.empty())
                    continue;

                iter = lmap.find(str);
                if(iter == lmap.end())
                    lmap[str] = 1;
                else 
                    iter->second++;
            }

            for(iter = lmap.begin();iter != lmap.end();iter++) {
                if(iter->second > maxfreq) {
                    maxfreq = iter->second;
                    result = iter->first;
                }
            }

            return result;
        }
};
