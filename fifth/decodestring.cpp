
class Solution {
    public:
        string subDecode(string &s, int &index, int n) {
            string str;

            while(index < s.size()) {
                char c = s[index];
                while(isalpha(c)) {
                    str.push_back(c);
                    index++;
                    c = s[index];
                }

                if(c == ']') {
                    index++;
                    break;
                } else {
                    string num;
                    while(s[index] >= '0' && s[index] <= '9') {
                        num.push_back(s[index]);
                        index++;
                    }
                    if(s[index] == '[') {
                        index++;
                        str.append(subDecode(s, index, strtol(num.c_str(), NULL, 0)));
                    }
                }
            }

            string result;
            for(int i = 0;i < n;i++) {
                result.append(str);
            }

            return result;
        }
        string decodeString(string s) {
            string result, str;
            int i, size = s.size();

            for(i = 0;i < size;) {
                char c = s[i];
                if(isalpha(c)) {
                    while(s[i] >= 'a' && s[i] <= 'z') {
                        str.push_back(s[i]);
                        i++;
                    }
                } else if(c >= '0' && c <= '9') {
                    string num;
                    while(s[i] >= '0' && s[i] <= '9') {
                        num.push_back(s[i]);
                        i++;
                    }
                    if(s[i] == '[') {
                        i++;
                        str.append(subDecode(s, i, strtol(num.c_str(), NULL, 0)));
                    }
                } else {
                    i++;
                }
                result.append(str);
                str.clear();
            }

            return result;
        }
};
