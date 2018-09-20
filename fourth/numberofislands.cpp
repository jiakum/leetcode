
class Solution {
    vector<vector<char>> state;
    int row, col;
    public:
    void search_island(vector<vector<char>>& grid, int i, int j) {
        if(grid[i][j] == '0' || state[i][j])
            return;

        state[i][j] = 1;
        if(i > 0)
            search_island(grid, i - 1, j);        
        if(i < row - 1)
            search_island(grid, i + 1, j);
        if(j > 0)
            search_island(grid, i, j - 1);        
        if(j < col - 1)
            search_island(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        row = grid.size();

        if(row == 0)
            return result;
        col = grid[0].size();
        if(col == 0)
            return result;

        int i, j;
        vector<char> vc;
        for(i = 0;i < col;i++) {
            vc.push_back(0);
        }
        state.clear();
        for(i = 0;i < row;i++) {
            state.push_back(vc);
        }

        for(i = 0;i < row;i++) {
            for(j = 0;j < col;j++) {
                if(grid[i][j] == '0' || state[i][j])
                    continue;

                search_island(grid, i, j);
                result++;
            }
        }

        return result;
    }
};
