
class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> result;
            int m = matrix.size();

            if(m == 0)
                return result;

            int n = matrix[0].size(), i, j;
            int rows = 0, colomns = 0;
            int rowe = m, colomne = n;
            while(rows < rowe && colomns < colomne) {
                for(i = colomns;i < colomne;i++) {
                    result.push_back(matrix[rows][i]);
                }
                if(rows + 1 == rowe)
                    break;
                for(i = rows + 1;i < rowe;i++) {
                    result.push_back(matrix[i][colomne - 1]);
                }
                for(i = colomne - 2;i >= colomns;i--) {
                    result.push_back(matrix[rowe - 1][i]);
                }
                if(colomns + 1 == colomne)
                    break;
                for(i = rowe - 2;i > rows;i--) {
                    result.push_back(matrix[i][colomns]);
                }
                rows++; rowe--;
                colomns++, colomne--;
            }

            return result;
        }
};
