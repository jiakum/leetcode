
class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> result;
            int m = n;

            if(n == 0)
                return result;

            int i, j, num = 1;
            int rows = 0, colomns = 0;
            int rowe = m, colomne = n;

            for(i = 0;i < n;i++) {
                vector<int> vi(n, 0);
                result.push_back(vi);
            }

            while(rows < rowe && colomns < colomne) {
                for(i = colomns;i < colomne;i++) {
                    result[rows][i] = num++;
                }
                if(rows + 1 == rowe)
                    break;
                for(i = rows + 1;i < rowe;i++) {
                    result[i][colomne - 1] = num++;
                }
                for(i = colomne - 2;i >= colomns;i--) {
                    result[rowe - 1][i] = num++;
                }
                if(colomns + 1 == colomne)
                    break;
                for(i = rowe - 2;i > rows;i--) {
                    result[i][colomns] = num++;
                }
                rows++; rowe--;
                colomns++, colomne--;        
            }

            return result;    
        }

};
