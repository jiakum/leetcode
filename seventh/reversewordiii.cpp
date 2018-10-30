
class Solution {
    public:
        string reverseWords(string s) {
            string result;
            stack<char> str;
            int i, size = s.size();

            if(size <= 1)
                return s;

            for(i = 0;i < size;i++) {
                while(i < size && s[i] != ' ') {
                    str.push(s[i]);
                    i++;
                }

                while(!str.empty()) {
                    result.push_back(str.top());
                    str.pop();
                }

                result.push_back(' ');
            }

            result.pop_back();

            return result;
        }
};
