
class Solution {
    public:
        void subFill(vector<vector<int>> & result, vector<vector<int>> &status, 
                int i, int j, int newColor, int flood) {
            int row = result.size(), col = result[0].size();

            if(i < 0 || j < 0 || i >= row || j >= col 
                    || result[i][j] != flood || status[i][j])
                return;

            result[i][j] = newColor;
            status[i][j] = 1;
            subFill(result, status, i - 1, j, newColor, flood);
            subFill(result, status, i + 1, j, newColor, flood);
            subFill(result, status, i, j - 1, newColor, flood);
            subFill(result, status, i, j + 1, newColor, flood);
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
            int row = image.size(), col = image[0].size();
            vector<vector<int>> status(row, vector<int>(col, 0)), result(image);

            subFill(result, status, sr, sc, newColor, image[sr][sc]);

            return result;
        }
};
