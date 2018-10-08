
class Solution {
    public:
        bool repeatedSubstringPattern(string s) {
            int size = s.size(), i;

            for(i = 1;i <= size / 2;i++) {
                if(size % i != 0)
                    continue;

                int n = size / i, found = true;
                string sub = s.substr(0, i);
                for(int j = 1;j < n;j++) {
                    if(strncmp(s.c_str() + i * j, sub.c_str(), i) != 0) {
                        found = false;
                        break;
                    }
                }

                if(found)
                    return true;
            }

            return false;
        }
};
