
class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> result;
            int i, j;

            if(numRows == 0)
                return result;

            for(i = 1;i <= numRows;i++) {
                vector<int> vi;

                vi.push_back(1);
                if(i > 1) {
                    for(j = 1;j < i - 1;j++) {
                        vector<int> &last = result.back();
                        int num = last[j - 1] + last[j];

                        vi.push_back(num);
                    }
                    vi.push_back(1);
                }

                result.push_back(vi);
            }

            return result;
        }
};
