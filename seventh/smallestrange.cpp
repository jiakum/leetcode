ass Solution {
    public:
        int smallestRangeI(vector<int>& A, int K) {
            int small = INT_MAX, big = INT_MIN;
            int i, size = A.size();

            for(i = 0;i < size;i++) {
                int n = A[i];
                small = min(small, n);
                big = max(big, n);
            }

            if(big - small <= K * 2)
                return 0;

            return big - small - K * 2;
        }
};
