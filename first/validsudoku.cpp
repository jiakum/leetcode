
class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            char found[10];
            int i, j;

            for(i = 0;i < 9;i ++) {
                char c;

                memset(found, 0, sizeof(found));
                for(j = 0;j < 9;j++) {
                    c = board[i][j];
                    if(c >= '1' && c <= '9') {
                        c = c - '1';
                        if(found[c])
                            return false;
                        else
                            found[c] = 1;
                    } else {
                        continue;
                    }
                }
            }   

            for(i = 0;i < 9;i ++) {
                char c;

                memset(found, 0, sizeof(found));
                for(j = 0;j < 9;j++) {
                    c = board[j][i];
                    if(c >= '1' && c <= '9') {
                        c = c - '1';
                        if(found[c])
                            return false;
                        else
                            found[c] = 1;
                    } else {
                        continue;
                    }
                }
            }    

            for(i = 0;i < 9;i ++) {
                char c;
                int row = (i / 3) * 3;

                memset(found, 0, sizeof(found));
                for(j = 0;j < 9;j++) {
                    int colomn = (i % 3) * 3;
                    c = board[row + j / 3][colomn + j % 3];
                    if(c >= '1' && c <= '9') {
                        c = c - '1';
                        if(found[c])
                            return false;
                        else
                            found[c] = 1;
                    } else {
                        continue;
                    }
                }
            }

            return true;
        }
};


