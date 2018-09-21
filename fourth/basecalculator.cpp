
class Solution {
    public:
        int calculate(string s) {
            vector<int> data, sign;
            for(int i = 0;i < s.size();) {
                switch(s[i]) {
                    case ' ':
                        i++;
                        break;
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                        sign.push_back(s[i]);
                        i++;
                        break;
                    default:
                        int num = 0, pre = 0;
                        while(isdigit(s[i])) {
                            num = num * 10 + (s[i] - '0');
                            i++;
                        }

                        if(!sign.empty()) {
                            switch(sign.back()) {
                                case '*':
                                    pre = data.back();

                                    data.pop_back();
                                    sign.pop_back();
                                    num = num * pre;
                                    break;
                                case '/': 
                                    pre = data.back();

                                    data.pop_back();
                                    sign.pop_back();
                                    num = pre / num;
                                    break;
                                default:
                                    break;
                            }
                        }
                        data.push_back(num);

                        break;
                }
            }

            int result = data[0];
            for(int i = 0;i < sign.size();i++) {
                int num = data[i + 1];
                switch(sign[i]) {
                    case '+':
                        result += num;
                        break;
                    case '-':
                        result -= num;
                        break;
                }
            }

            return result;
        }
};
