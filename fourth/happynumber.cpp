
class Solution {
    public:
        bool isHappy(int n) {
            map<int, int> imap;
            stack<int> vi;

            while(n != 1) {
                if(imap.find(n) != imap.end())
                    return false;

                imap[n] = n;

                while(n > 0) {
                    int des = n % 10;
                    n /= 10;

                    vi.push(des);
                }

                n = 0;
                while(!vi.empty()) {
                    n += vi.top() * vi.top();
                    vi.pop();
                }
            }

            return true;
        }
};
