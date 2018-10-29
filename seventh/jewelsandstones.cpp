
class Solution {
    public:
        int numJewelsInStones(string J, string S) {
            unordered_map<char, int> lmap;
            unordered_map<char, int>::iterator iter;
            int i, result = 0;

            for(i = 0;i < J.size();i++) {
                char c = J[i];

                lmap[c] = 1;
            }
            for(i = 0;i < S.size();i++) {
                char c = S[i];

                iter = lmap.find(c);
                if(iter != lmap.end())
                    result++;
            }

            return result;
        }
};
