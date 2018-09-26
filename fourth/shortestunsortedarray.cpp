
class Solution {
    public:
        int findUnsortedSubarray(vector<int>& nums) {
            vector<int> orig(nums);

            sort(nums.begin(), nums.end());

            int i, j;
            for(i = 0;i < nums.size();i++)
                if(orig[i] != nums[i])
                    break;

            if(i == nums.size())
                return 0;

            for(j = nums.size() - 1;j >= 0;j--)
                if(orig[j] != nums[j])
                    break;

            return j - i + 1;
        }
};
