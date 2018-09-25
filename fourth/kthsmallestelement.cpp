
class Solution {
    public:
        int kthSmallest(vector<vector<int>>& matrix, int k) {
            int row = matrix.size();
            if(row == 0)
                return 0;
            int col = matrix[0].size();
            if(col == 0)
                return 0;

            map<int,int> imap;
            map<int,int>::iterator iter;
            for(int i = 0;i < row;i++) {
                for(int j = 0;j < col;j++) {
                    int num = matrix[i][j];
                    iter = imap.find(num);
                    if(iter == imap.end())
                        imap[num] = 1;
                    else
                        imap[num]++;
                }
            }

            k = k % (row * col + 1);
            for(iter = imap.begin();iter != imap.end();iter++) {
                k -= iter->second;
                if(k <= 0)
                    break;
            }

            return iter->first;
        }
};
