
class Solution {
    public:
        void reverseWords(string &s) {
            int i, j, len = s.size(), end;
            string pos(s);

            s.clear();
            for(j = len - 1;j >= 0;j--) {
                string str;
                while(pos[j] == ' ') j--;

                end = j;
                while(pos[j] != ' ' && j >= 0)  {
                    j--;
                }
                for(i = j + 1;i <= end;i++) {
                    s.push_back(pos[i]);                
                }

                s.push_back(' ');
            }

            while(s.back() == ' ')
                s.pop_back();
        }
};
