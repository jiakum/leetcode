
class Solution {
    public:
        vector<int> shortestToChar(string S, char C) {
            set<int> data;
            set<int>::iterator iter;
            int i, size = S.size();

            for(i = 0;i < size;i++) {
                if(S[i] == C) {
                    data.insert(i);
                }
            }

            vector<int> result;
            for(iter = data.begin();iter != data.end();) {
                int start = *iter, next = INT_MAX;

                while (result.size() <= start) {
                    result.push_back(start - result.size());
                }

                iter++;
                if(iter != data.end())            
                    next = *iter;

                int end = min(next, size);
                while(result.size() < end) {
                    int val = min(result.size() - start, next - result.size());

                    result.push_back(val);
                }
            }

            return result;
        }
};
