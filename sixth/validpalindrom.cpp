
class Solution {
    public:
        bool palindrome(string s) {
            int size = s.size();
            for(int i = 0;i < size / 2;i++) {
                if(s[i] != s[size - i - 1])
                    return false;
            }

            return true;
        }
        bool validPalindrome(string s) {
            int left, right, size = s.size();
            bool result = true;

            left = 0; right = size - 1;

            while(left < right) {
                if(s[left] != s[right]) {                
                    result = palindrome(s.substr(left + 1, right - left))
                        || palindrome(s.substr(left, right - left));

                    break;
                }

                left++;
                right--;
            }

            return result;
        }
};
