
class Solution {
    public:
        int peakIndexInMountainArray(vector<int>& A) {
            int i, size = A.size();

            for(i = 1;i < size;i++) {
                if(A[i] < A[i - 1])
                    return i - 1;
            }

            return A[0];
        }
};
