
class Solution {
    public:
        vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
            unordered_set<int> data;
            vector<int> result;
            int total = 0, i, nb = 0;

            for(i = 0;i < A.size();i++) {
                total += A[i];
                data.insert(A[i]);
            }        
            for(i = 0;i < B.size();i++) {
                nb += B[i];
            }

            total = (total + nb) >> 1;
            for(i = 0;i < B.size();i++) {
                int n = total - (nb - B[i]);

                if(data.find(n) != data.end()) {
                    result.push_back(n);
                    result.push_back(B[i]);
                    break;
                }
            }

            return result;
        }
};
