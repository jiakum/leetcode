
class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> result;
            int i, j, psize = p.size(), size = s.size();

            if(size == 0 || psize == 0 || size < psize)
                return result;

            short lmap[26], back[26];

            memset(back, 0, sizeof(back));
            memset(lmap, 0, sizeof(lmap));
            for(i = 0;i < psize;i++) {
                char c = p[i];
                c -= 'a';
                back[c]++;

                c = s[i];
                c -= 'a';
                lmap[c]++;
            }

            if(memcmp(lmap, back, sizeof(back)) == 0)
                result.push_back(0);
            for(i = psize;i < size;i++) {
                char c = s[i] - 'a';
                //printf("c:%d, back:%d\n", c, back[c]);
                lmap[c]++;
                c = s[i - psize] - 'a';
                lmap[c]--;
                if(memcmp(lmap, back, sizeof(back)) == 0)
                    result.push_back(i - psize + 1);
            }

            return result;
        }
};
