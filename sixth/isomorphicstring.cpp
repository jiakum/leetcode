
class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            if(s.size() != t.size())
                return false;

            map<char, char> smap, tmap;
            map<char, char>::iterator siter, titer;
            int i, size = s.size();
            for(i = 0;i < size;i++) {
                char c = s[i], d = t[i];

                siter = smap.find(c);
                titer = tmap.find(d);
                if(siter != smap.end()) {
                    if(titer == tmap.end() || d != siter->second)
                        return false;

                } else {
                    if(titer != tmap.end())
                        return false;

                    smap[c] = d;
                    tmap[d] = c;
                }
            }

            return true;
        }
};
