
class Solution {
    public:
        int compress(vector<char>& chars) {
            int i, size = chars.size(), ptr = 0;

            for(i = 0;i < size;) {
                char c = chars[i];
                int n = 1;

                chars[ptr++] = c;
                i++;
                while(chars[i] == c && i < size) {
                    n++;
                    i++;
                }

                if(n == 1)
                    continue;

                char num[16], *buf = num;
                snprintf(num, sizeof(num), "%d", n);
                while(*buf != '\0') {
                    chars[ptr++] = *buf++;
                }
            }

            return ptr;
        }
};
