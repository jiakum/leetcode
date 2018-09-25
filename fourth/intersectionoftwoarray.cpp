
class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            vector<int> snum1(nums1), snum2(nums2), result;
            int i, j;

            sort(snum1.begin(), snum1.end());
            sort(snum2.begin(), snum2.end());

            for(i = 0, j = 0;i < snum1.size() && j < snum2.size();) {
                int n1 = snum1[i], n2 = snum2[j];
                if(n1 < n2) {
                    i++;
                } else if(n1 == n2){
                    result.push_back(n1);
                    i++;
                    j++;
                } else {
                    j++;
                }
            }

            return result;
        }
};
