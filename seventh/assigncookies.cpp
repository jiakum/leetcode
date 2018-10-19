
class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            vector<int> greed(g), cookie(s);

            if(g.empty() || s.empty())
                return 0;

            sort(greed.begin(), greed.end());
            sort(cookie.begin(), cookie.end());

            int result = 0, j = 0, size = s.size();
            for(int i = 0;i < g.size();i++) {
                while(greed[i] > cookie[j] && j < size) {
                    j++;
                }
                if(j >= size)
                    break;
                if(greed[i] <= cookie[j]) {
                    result++;
                    j++;
                }
            }

            return result;
        }
};
