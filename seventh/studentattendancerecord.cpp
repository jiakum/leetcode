
class Solution {
    public:
        bool checkRecord(string s) {
            int i, size = s.size(), late = 0, absence = 0;

            for(i = 0;i < size;i++) {
                char c = s[i];

                if(c == 'L') {
                    late++;
                    if(late == 3)
                        return false;
                } else {
                    if(c == 'A') {
                        absence++;
                        if(absence == 2)
                            return false;
                    }
                    late = 0;
                }
            }

            return true;
        }
};
