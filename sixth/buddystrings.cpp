
class Solution {
    public:
        bool buddyStrings(string A, string B) {
            int result = 0, size = A.size();

            if(size != B.size())
                return false;

            vector<int> vi;
            int dp[26];
            memset(dp, 0, sizeof(dp));
            for(int i = 0;i < size;i++) {
                if(A[i] != B[i]) {
                    result ++;
                    if(result > 2)
                        return false;

                    vi.push_back(i);
                }
                dp[A[i] - 'a']++;
            }

            if(vi.size() == 1)
                return false;
            else if(vi.size() == 2) {
                if((A[vi[0]] == B[vi[1]]) && (A[vi[1]] == B[vi[0]]))
                    return true;
                else
                    return false;
            } else {
                for(int i = 0;i < 26;i++) {
                    if(dp[i] > 1)
                        return true;
                }

                return false;
            }
        }
};
