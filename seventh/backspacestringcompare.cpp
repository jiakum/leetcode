
class Solution {
    public:
        bool backspaceCompare(string S, string T) {
            string str, ttr;

            for(int i = 0;i < S.size();i++) {
                char c = S[i];
                if(c == '#') {
                    if(!str.empty())
                        str.pop_back();
                } else {
                    str.push_back(c);
                }
            }
            for(int i = 0;i < T.size();i++) {
                char c = T[i];
                if(c == '#') {
                    if(!ttr.empty())
                        ttr.pop_back();
                } else {
                    ttr.push_back(c);
                }
            }

            return str == ttr;
        }
};
