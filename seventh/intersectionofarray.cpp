
class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> data, result;

            for(int i = 0;i < nums1.size();i++) {
                data.insert(nums1[i]);
            }
            for(int i = 0;i < nums2.size();i++) {
                int n = nums2[i];
                if(data.find(n) != data.end())
                    result.insert(n);
            }

            return vector<int>(result.begin(), result.end());
        }
};
