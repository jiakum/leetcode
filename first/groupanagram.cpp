
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            map<string,int> smap;
            map<string,int>::iterator iter;
            vector<vector<string>> result;
            int i, size = strs.size(), ptr = 0;

            for(i = 0;i < size;i++) {
                string s = strs[i];

                sort(s.begin(), s.end());

                iter = smap.find(s);
                if(iter != smap.end()) {
                    result[iter->second].push_back(strs[i]);
                } else {
                    vector<string> vs;

                    vs.push_back(strs[i]);
                    result.push_back(vs);
                    smap[s] = ptr++;
                }
            }

            return result;
        }
};
