
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int row = matrix.size();
            if(row == 0)
                return false;
            int col = matrix[0].size();
            if(col == 0)
                return false;

            int left = 0, right = col - 1, found = -1, mid;

            for(found = left;found <= right;found++) {
                if(target >= matrix[0][found] && target <= matrix[row - 1][found]) {
                    int top = 0, bottom = row - 1;
                    while(top <= bottom) {
                        mid = (top + bottom) / 2;
                        if(target == matrix[mid][found]) {
                            return true;;
                        }

                        if(target > matrix[mid][found])
                            top = mid + 1;
                        else
                            bottom = mid - 1;
                    }
                }
            }

            return false;
        }
};
