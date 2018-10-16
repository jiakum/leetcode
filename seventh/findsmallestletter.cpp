
class Solution {
    public:
        char nextGreatestLetter(vector<char>& letters, char target) {
            for(int i = 0;i < letters.size();i++) {
                char c = letters[i];

                if(c > target)
                    return c;
            }

            return letters[0];
        }
};
