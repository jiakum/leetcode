
class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> nums;
            int i, size = tokens.size(), num;

            for(i = 0;i < size;i++) {
                string &str = tokens[i];
                char c = str[0];

                if((str.size() == 1) && 
                        (c == '+' || c == '-' || c == '/' || c == '*')) {
                    int m = nums.top();
                    nums.pop();
                    int n = nums.top();
                    nums.pop();
                    switch(c) {
                        case '+':
                            num = m + n;
                            break;
                        case '-':
                            num = n - m;
                            break;
                        case '/':
                            num = n / m;
                            break;
                        case '*':
                            num = n * m;
                            break;
                    }

                } else {
                    num = strtol(str.c_str(), NULL, 0);
                }
                nums.push(num);
            }

            return nums.top();
        }
};
