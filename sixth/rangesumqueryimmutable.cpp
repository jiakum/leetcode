
class NumArray {
    vector<int> data;
    public:
    NumArray(vector<int> nums) {
        int total = 0;

        for(int i = 0;i < nums.size();i++) {
            total += nums[i];

            data.push_back(total);
        }
    }

    int sumRange(int i, int j) {
        int result = data[j];

        if(i > 0)
            result -= data[i - 1];

        return result;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
