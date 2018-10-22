
class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            unordered_map<char, int> lmap;
            unordered_map<char, int>::iterator iter;

            for(int i = 0;i < magazine.size();i++) {
                char c = magazine[i];

                iter = lmap.find(c);
                if(iter == lmap.end())
                    lmap[c] = 1;
                else
                    iter->second++;
            }
            for(int i = 0;i < ransomNote.size();i++) {
                char c = ransomNote[i];

                iter = lmap.find(c);
                if(iter == lmap.end())
                    return false;
                else if(--iter->second < 0)
                    return false;
            }

            return true;
        }
};
