
class Solution {
    public:
        string licenseKeyFormatting(string S, int K) {
            string result;
            int i, size = S.size(), n = K;

            for(i = size - 1;i >= 0;i--) {
                char c = S[i];
                if(c == '-')
                    continue;

                c = toupper(c);

                n--;
                result.push_back(c);

                if(n == 0) {
                    result.push_back('-');
                    n = K;
                }
            }

            if(result.back() == '-')
                result.pop_back();
            reverse(result.begin(), result.end());

            return result;
        }
};
