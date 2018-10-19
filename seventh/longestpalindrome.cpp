
class Solution {
    public:
        int longestPalindrome(string s) {
            unordered_map<char, int> lmap;
            unordered_map<char, int>::iterator iter;

            for(int i = 0;i < s.size();i++) {
                char c = s[i];

                iter = lmap.find(c);
                if(iter != lmap.end())
                    iter->second++;
                else                
                    lmap[c] = 1;
            }

            int total = 0, tail = 0;
            for(iter = lmap.begin();iter != lmap.end();iter++) {
                total += iter->second & ~0x01;
                if(iter->second & 0x01)
                    tail = 1;
            }

            return total + tail;
        }
};
