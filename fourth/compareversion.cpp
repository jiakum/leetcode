
class Solution {
    public:
        int getSubNumber(const char **buf) {
            const char *ptr = *buf;
            string num;

            while(*ptr == '.') ptr++;
            while(*ptr != '.' && *ptr != '\0') {
                num.push_back(*ptr);
                ptr++;
            }

            *buf = ptr;
            return strtol(num.c_str(), NULL, 0);
        }
        int compareVersion(string version1, string version2) {
            const char *v1 = version1.c_str(), *v2 = version2.c_str();

            while(*v1 || *v2) {
                int n1 = getSubNumber(&v1);
                int n2 = getSubNumber(&v2);
                if(n1 == n2)
                    continue;

                return n1 > n2 ? 1: -1;
            }

            return 0;
        }
};
