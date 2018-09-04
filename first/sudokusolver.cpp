
class Solution {
    public:
        bool solveSudoku(vector<vector<char>>& board, int i = -1) {
            while (++i < 81) if (board[i / 9][i % 9] == '.' || board[i / 9][i % 9] == ':') {
                for (board[i / 9][i % 9] = '1'; board[i / 9][i % 9] <= '9'; ++board[i / 9][i % 9])  {
                    if (isValid(board, i) && solveSudoku(board, i)) 
                        return true;
                }
                return false;
            }
            return true;
        }
        bool isValid(vector<vector<char>>& board, int t) {
            for (int i = 0; i < 9; ++i) {
                if ((i != t/9 && board[i][t%9] == board[t/9][t%9]) 
                        || (i != t%9 && board[t/9][i] == board[t/9][t%9]) 
                        || (t/27*27+t%9/3*3+i/3*9+i%3 != t 
                            && board[t/27*3+i/3][t%9/3*3+i%3] == board[t/9][t%9])
                   ) 
                    return false;
            }
            return true;
        }
};
