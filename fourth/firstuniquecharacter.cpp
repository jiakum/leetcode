
class Solution {
    public:
        int firstUniqChar(string s) {
            pair<int, int> num[26];
            for(int i = 0;i < 26;i++) {
                num[i] = pair<int, int> (0, 0);
            }

            for(int i = 0;i < s.size();i++) {
                int index = s[i] - 'a';
                pair<int,int> &p = num[index];
                p.first++;
                if(p.first == 1) {
                    p.second = i;
                }
            }

            vector<int> result;
            for(int i = 0;i < 26;i++) {
                pair<int,int> &p = num[i];
                if(p.first == 1)
                    result.push_back(p.second);
            }
            sort(result.begin(), result.end());

            return result.empty() ? -1:result[0];
        }
};
