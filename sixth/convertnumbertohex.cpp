
class Solution {
    public:
        string toHex(int num) {
            unsigned int n = num;
            int i;
            string result;

            for(i = 28;i >= 0;i -= 4) {
                unsigned int h = (n & (0x0f << i)) >> i;
                char c;

                if(h >= 10) {
                    c = h - 10 + 'a';
                } else {
                    c = h + '0';
                }

                if(result.size() > 0 || c != '0')
                    result.push_back(c);
            }

            if(result.size() == 0)
                result.push_back('0');

            return result;
        }
};
