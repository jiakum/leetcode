
class Solution {
    public:
        void subReverse(vector<string> &result, string &str, int start) {
            int size = str.size();
            if(start >= size) {
                result.push_back(str);
                return;
            }

            char c = str[start];

            subReverse(result, str, start + 1);
            if(islower(c) || isupper(c)) {
                if(islower(c)) {
                    str[start] = toupper(c);
                    subReverse(result, str, start + 1);
                } else {
                    str[start] = tolower(c);
                    subReverse(result, str, start + 1);
                }

                str[start] = c;
            }
        }
        vector<string> letterCasePermutation(string S) {
            vector<string> result;
            string str = S;

            subReverse(result, str, 0);

            return result;
        }
};
