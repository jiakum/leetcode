
class Solution {
    vector<int> data;
    public:
    Solution(vector<int> nums) {
        data = nums;
        srand((unsigned)time(0));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return data;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result(data);
        int size = data.size();
        for(int i = 0;i < size;i++) {
            int tmp = rand() % size;
            swap(result[i], result[tmp]);
        }

        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
