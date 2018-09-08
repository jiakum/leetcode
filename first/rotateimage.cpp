
class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int w = matrix.size(), i, j;

            for(i = 0;i < w;i++) {
                for(j = i;j < w - i - 1;j++) {
                    int tmp = matrix[i][j];

                    matrix[i][j] = matrix[w - j - 1][i];

                    matrix[w - j - 1][i] = matrix[w - i - 1][w - j - 1];

                    matrix[w - i - 1][w - j - 1] = matrix[j][w - i - 1];

                    matrix[j][w - i - 1] = tmp;      
                }
            }
        }
};
