
class Solution {
    public:
        vector<vector<int>> largeGroupPositions(string S) {
            vector<vector<int>> result;
            int i, size = S.size();

            for(i = 0;i < size;i++) {
                char c = S[i];
                int len = 1, start = i;

                while(i + 1 < size && S[i + 1] == c) {
                    len++;
                    i++;
                }

                if(len >= 3) {
                    vector<int> vi;

                    vi.push_back(start);
                    vi.push_back(i);
                    result.push_back(vi);
                }
            }

            return result;
        }
};
