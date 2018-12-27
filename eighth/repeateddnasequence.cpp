
class Solution {
    public:
        vector<string> findRepeatedDnaSequences(string s) {
            unordered_map<string, int> lmap;
            unordered_map<string, int>::iterator iter;
            unordered_set<string> result;
            int i, size = s.size();

            for(i = 0;i <= size - 10;i++) {
                string str = s.substr(i, 10);

                iter = lmap.find(str);
                if(iter == lmap.end())
                    lmap[str] = 1;
                else
                    result.insert(str);
            }

            return vector<string> (result.begin(), result.end());
        }
};
