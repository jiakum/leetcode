
class Solution {
    public:
        string reverseStr(string s, int k) {
            int i, size = s.size(), left = size;
            string result;

            for(i = 0;i < size;i += k * 2) {
                int end = min(size - 1, i + k - 1);
                for(int j = end;j >= i;j--) {
                    result.push_back(s[j]);
                }
                end = min(size, i + k * 2);
                for(int j = i + k;j < end;j++) {
                    result.push_back(s[j]);
                }
            }

            return result;
        }
};
