
class Solution {
    public:
        vector<vector<int>> transpose(vector<vector<int>>& A) {
            vector<vector<int>> result;
            int row = A.size(), col = A[0].size();
            int i, j;

            for(j = 0;j < col;j++) {
                vector<int> vi;
                for(i = 0;i < row;i++) {
                    vi.push_back(A[i][j]);
                }

                result.push_back(vi);
            }

            return result;
        }
};
