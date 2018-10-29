
class Solution {
    public:
        vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
            vector<vector<int>> result(A);
            int i, j, row = A.size();

            for(i  = 0;i< row;i++) {
                vector<int> &vi = result[i];
                int col = vi.size();
                for(j = 0;j < col / 2;j++) {
                    int left = vi[j];
                    int right = vi[col - j - 1];

                    vi[j] = !right;
                    vi[col - j - 1] = !left;
                }

                if(col & 0x01) {
                    vi[col / 2] = !vi[col / 2];
                }
            }

            return result;
        }
};
