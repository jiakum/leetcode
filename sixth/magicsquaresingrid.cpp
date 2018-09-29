
class Solution {
    public:
        bool isMagic(int row, int col, vector<vector<int>>& grid) {
            char table[16];
            memset(table, 0, sizeof(table));

            char rsum[3], lsum[3], diag[2];
            memset(rsum, 0, sizeof(rsum));
            memset(lsum, 0, sizeof(lsum));
            memset(diag, 0, sizeof(diag));

            for(int i = 0;i < 3;i++) {
                for(int j = 0;j < 3;j++) {
                    int n = grid[i + row][j + col];
                    if(table[n] || n < 1 || n > 9)
                        return false;

                    table[n] = 1;
                    rsum[i] += n;
                    lsum[j] += n;
                    if(i == j)
                        diag[0] += n;
                    if((i == 0 && j == 2) || (i == 1 && j == 1) || (i == 2 && j == 0))
                        diag[1] += n;
                }
            }

            return (rsum[0] == rsum[1]) && (rsum[0] == rsum[2]) 
                && (lsum[0] == lsum[1]) && (lsum[0] == lsum[2])
                && (rsum[0] == lsum[0]) && (rsum[0] == diag[0])
                && (diag[0] == diag[1]);
        }
        int numMagicSquaresInside(vector<vector<int>>& grid) {
            int row = grid.size(), col = grid[0].size(), result = 0;

            for(int i = 0;i <= row - 3;i++) {
                for(int j = 0;j <= col - 3;j++) {
                    if(isMagic(i, j, grid)) {
                        printf("i:%d,j:%d\n", i, j);
                        result++;
                    }
                }
            }

            return result;
        }
};
