
class Solution {
    public:
        void subcombine(vector<vector<int>> &result, vector<int> &vi, int s, int n, int k)
        {
            int i;

            if(k == 0) {
                result.push_back(vi);
                return;
            }

            for(i = s + 1;i <= n;i++) {
                vi.push_back(i);
                subcombine(result, vi, i, n, k - 1);
                vi.pop_back();
            } 
        }
        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> result;
            vector<int> vi;

            subcombine(result, vi, 0, n, k);

            return result;
        }
};
