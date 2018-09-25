
class Solution {
    public:
        vector<string> fizzBuzz(int n) {
            vector<string> result;
            char *ptr, num[16];
            for(int i = 1;i <= n;i++) {
                if(i % 3 == 0) {
                    if(i % 5 == 0)
                        ptr = "FizzBuzz";
                    else
                        ptr = "Fizz";
                } else if(i % 5 == 0) {
                    ptr = "Buzz";
                } else {
                    snprintf(num, sizeof(num), "%d", i);
                    ptr = num;
                }

                result.push_back(ptr);
            }

            return result;
        }
};
