class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int row = matrix.size();
            if(row == 0)
                return false;

            int col = matrix[0].size();
            if(col == 0)
                return false;

            int top = 0, bottom = row - 1, found = top;

            while(top <= bottom) {
                int mid = (top + bottom) >> 1;
                if(target >= matrix[mid][0] && target <= matrix[mid][col - 1]) {
                    found = mid;
                    break;
                }  

                if(target < matrix[mid][0]) {
                    bottom = mid - 1;
                    continue;
                } else if(target > matrix[mid][col - 1]) {
                    top = mid + 1;
                    continue;
                }
            }

            int left = 0, right = col - 1;
            do {
                int mid = (left + right) >> 1;
                if(target == matrix[found][mid])
                    return true;

                if(target < matrix[found][mid]) {
                    right = mid - 1;
                    continue;
                } else if(target > matrix[found][mid]) {
                    left = mid + 1;
                    continue;
                }
            } while(left <= right);

            return false;
        }
};
