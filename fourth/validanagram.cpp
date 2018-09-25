
class Solution {
    public:
        bool isAnagram(string s, string t) {
            int size = s.size();
            if(t.size() != size)
                return false;

            unordered_map<char,int> lmap;
            unordered_map<char,int>::iterator iter;
            for(int i = 0;i < size;i++) {
                char c = s[i];
                iter = lmap.find(c);
                if(iter == lmap.end()) {
                    lmap[c] = 1;
                } else {
                    iter->second++;
                }
            }

            for(int i = 0;i < size;i++) {
                char c = t[i];
                iter = lmap.find(c);
                if(iter == lmap.end()) {
                    return false;
                } else {
                    iter->second--;
                    if(iter->second < 0)
                        return false;
                }
            }

            return true;
        }
};
