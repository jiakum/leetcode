
class Solution {
    int row, col, size;
    public:
    bool dfs_search(int i, int j, int k,
            vector<vector<int>>& state, vector<vector<char>>& tboard,string &sword ) {
        bool ret;

        if(k == size)
            return true;

        if(i > 0 && !state[i - 1][j] && tboard[i - 1][j] == sword[k]) {
            state[i - 1][j] = 1;            
            ret = dfs_search(i - 1, j, k + 1, state, tboard, sword);
            state[i - 1][j] = 0;
            if(ret)
                return true;        
        }        
        if(j > 0 && !state[i][j - 1] && tboard[i][j - 1] == sword[k]) {
            state[i][j - 1] = 1;
            ret = dfs_search(i, j - 1, k + 1, state, tboard, sword);
            state[i][j - 1] = 0;
            if(ret)
                return true; 
        }        
        if(i < row - 1 && tboard[i + 1][j] == sword[k] && !state[i + 1][j] ) {
            state[i + 1][j] = 1;
            ret = dfs_search(i + 1, j, k + 1, state, tboard, sword);
            state[i + 1][j] = 0;
            if(ret)
                return true; 
        }        
        if(j < col - 1 && !state[i][j + 1] && tboard[i][j + 1] == sword[k]) {
            state[i][j + 1] = 1;            
            ret = dfs_search(i, j + 1, k + 1, state, tboard, sword);
            state[i][j + 1] = 0; 
            if(ret)
                return true;            
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        size = word.size();

        if(row == 0 || size == 0)
            return false;

        col = board[0].size();
        if(col == 0)
            return false;

        int i, j, k;
        vector<vector<int>> state;
        vector<int> vi;
        for(j = 0;j < col;j++)
            vi.push_back(0);
        for(i = 0;i < row;i++) {
            state.push_back(vi);
        }

        {
            char c = word[0];
            bool found = false;
            for(i = 0;i < row;i++) {
                for(j = 0;j < col;j++) {
                    if(c == board[i][j]) {
                        state[i][j] = 1;
                        if(dfs_search(i, j, 1, state, board, word))
                            return true;
                        state[i][j] = 0;
                    }
                }
            }
        }

        return false;
    }
};
