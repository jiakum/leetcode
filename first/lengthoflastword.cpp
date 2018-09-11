

class Solution {
    public:
        int lengthOfLastWord(string s) {
            int end, i;

            i = s.size() - 1;
            while(i >= 0 && s[i] == ' ') {
                i--;
            }
            if(i == -1)
                return 0;

            end = i;
            while(i >= 0 && s[i] != ' ') {
                i--;
            }

            return end - i;
        }
};
