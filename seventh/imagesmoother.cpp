
class Solution {
    public:
        int average(vector<vector<int>>& matrix, int i, int j) {
            int row = matrix.size(), col = matrix[0].size();
            int total = matrix[i][j], n = 1;

            if(i > 0) {
                total += matrix[i - 1][j];
                n++;
                if(j > 0) {
                    n++;
                    total += matrix[i - 1][j - 1];
                }
                if(j + 1 < col) {
                    n++;
                    total += matrix[i - 1][j + 1];
                }
            }
            if(j > 0) {
                n++;
                total += matrix[i][j - 1];
            }
            if(j + 1 < col) {
                n++;
                total += matrix[i][j + 1];
            }
            if(i + 1 < row) {
                total += matrix[i + 1][j];
                n++;
                if(j > 0) {
                    n++;
                    total += matrix[i + 1][j - 1];
                }
                if(j + 1 < col) {
                    n++;
                    total += matrix[i + 1][j + 1];
                }
            }

            return total / n;
        }
        vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
            vector<vector<int>> result;

            for(int i = 0;i < M.size();i++) {
                vector<int> &vi = M[i], rev;
                for(int j = 0;j < vi.size();j++) {
                    rev.push_back(average(M, i, j));
                }

                result.push_back(rev);
            }

            return result;
        }
};
