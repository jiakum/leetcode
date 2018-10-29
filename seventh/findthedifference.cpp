
class Solution {
    public:
        char findTheDifference(string s, string t) {
            unordered_map<char, int> lmap;
            unordered_map<char, int>::iterator iter;
            int i, size = s.size();

            for( i = 0;i < size;i++) {
                char c = s[i];

                iter = lmap.find(c);
                if(iter == lmap.end())
                    lmap[c] = 1;
                else
                    iter->second++;
            }        
            for( i = 0;i < t.size();i++) {
                char c = t[i];

                iter = lmap.find(c);
                if(iter == lmap.end())
                    return c;
                else if(--iter->second < 0)
                    return c;
            }

            return '\0';
        }
};
