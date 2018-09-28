
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
    public:
        int firstBadVersion(int n) {
            unsigned int left = 1, right = n;
            int result = 0;

            while(left <= right) {
                int mid = (left + right) / 2;

                if(isBadVersion(mid)) {
                    result = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            return result;
        }
};
