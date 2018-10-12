
class Solution {
    public:
        bool is_vowel(char c) {
            c = tolower(c);
            return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o')
                || (c == 'u');
        }
        string reverseVowels(string s) {
            string result(s);
            int left = 0, right = s.size() - 1;

            while(left < right) {
                char c;

                while(left < right && !is_vowel(result[left])) {
                    left++;
                }
                while(left < right && !is_vowel(result[right])) {
                    right--;
                }

                if(left >= right)
                    break;

                c = result[left];
                result[left] = result[right];
                result[right] = c;

                left++;
                right--;
            }

            return result;
        }
};
