
class Solution {
    public:
        void setZeroes(vector<vector<int> > &matrix) {
            int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
            bool zrows[rows], zcols[cols];

            memset(zrows, 0, sizeof(zrows));
            memset(zcols, 0, sizeof(zcols));

            int i, j;

            for(i = 0;i < rows;i++) {
                for(j = 0;j < cols;j++) {
                    if(matrix[i][j] == 0) {
                        zrows[i] = true;
                        zcols[j] = true;
                    }
                }
            }   

            for(i = 0;i < rows;i++) {
                for(j = 0;j < cols;j++) {
                    if(zrows[i] || zcols[j]) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
};
