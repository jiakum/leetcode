
class Solution {
    public:
        int square(vector<vector<char>>& matrix, int i, int j) {
            int row = matrix.size(), col = matrix[0].size(), result;
            int x, y;

            for(result = 1;i + result < row && j + result < col;result++) {
                for(x = i, y = j + result;x <= i + result;x++){
                    if(matrix[x][y] == '0')
                        goto end;
                }
                for(x = i + result, y = j;y <= j + result;y++){
                    if(matrix[x][y] == '0')
                        goto end;
                }
            }

end:
            return result;
        }
        int maximalSquare(vector<vector<char>>& matrix) {
            int row = matrix.size();

            if(row == 0)
                return 0;

            int col = matrix[0].size(), i, j, result = 0;
            for(i = 0;i < row;i++) {
                for(j = 0;j < col;j++) {
                    if(matrix[i][j] == '1')
                        result = max(result, square(matrix, i, j));
                }
            }

            return result * result;
        }
};
