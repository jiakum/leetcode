
class Solution {
    public:
        int climbStairs(int n) {
            if(n <= 1)
                return n;

            int prevprev, prev, i, result;

            prevprev = 1;
            prev = 1;
            for(i = 2;i <= n;i++) {
                result = prevprev + prev;
                prevprev = prev;
                prev = result;
            }

            return result;
        }
};
