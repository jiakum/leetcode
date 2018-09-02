
class Solution {
    public:
        int strStr(string haystack, string needle) {
            int msize = haystack.size(), nsize = needle.size();

            if(nsize == 0)
                return 0;
            if(msize == 0)
                return -1;

            int pos = haystack.find(needle);

            return pos == string::npos ?  -1: pos;
        }
};
