
class Solution {
    public:
        bool detectCapitalUse(string word) {
            int size = word.size();
            if(size == 0)
                return false;

            if(islower(word[0])) {
                for(int i = 1;i < size;i++) {
                    if(!islower(word[i]))
                        return false;
                }

                return true;
            } else {
                if(size == 1)
                    return true;

                int lower = islower(word[1]);
                for(int i = 1;i < size;i++) {
                    if(islower(word[i]) != lower)
                        return false;
                }

                return true;
            }
        }
};
