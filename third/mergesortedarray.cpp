
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i, j;
            vector<int> vi;

            for(i = 0;i < m;i++)
                vi.push_back(nums1[i]);

            nums1.clear();
            for(i = 0, j = 0;i < m || j < n;) {
                if(i < m && j < n) {
                    if(vi[i] > nums2[j]) {
                        nums1.push_back(nums2[j++]);
                    } else {
                        nums1.push_back(vi[i++]);
                    }
                } else if(i < m) {
                    while(i < m) {
                        nums1.push_back(vi[i++]);                    
                    }
                } else {
                    while(j < n) {
                        nums1.push_back(nums2[j++]);                    
                    }
                }
            }
        }
};
