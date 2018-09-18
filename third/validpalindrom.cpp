
class Solution {
    public:
        bool alphanumeric(char c) {
            return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
        }
        bool isPalindrome(string s) {
            int size = s.size();
            int i, j;

            if(size <= 1)
                return true;

            for(i = 0, j = size - 1;i <= j;i++,j--) {
                char left;
                char right;
                left = s[i];
                while(!alphanumeric(left) && i <= j) {
                    left = s[++i];
                };
                right = s[j];
                while(!alphanumeric(right) && i <= j) {
                    right = s[--j];
                };

                if(i > j)
                    break;
                left = tolower(left);
                right = tolower(right);
                if(left != right)
                    return false;
            }

            return true;
        }
};
