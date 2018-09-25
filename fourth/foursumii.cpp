
class Solution {
    public:
        int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
            int N = A.size();
            unordered_map<int, int> upSum;
            unordered_map<int, int>::iterator iter;
            for (auto a : A) {
                for (auto b : B) {
                    int n = a + b;
                    iter = upSum.find(n);
                    if(iter == upSum.end())
                        upSum[n] = 1;
                    else 
                        iter->second++;
                }
            }
            int sum = 0;
            for (auto c : C) {
                for (auto d : D) {
                    iter = upSum.find(-c - d);
                    if(iter != upSum.end())
                        sum += iter->second;
                }
            }
            return sum;
        }
};
