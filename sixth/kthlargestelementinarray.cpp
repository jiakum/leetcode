
class KthLargest {
    multiset<int> data;
    multiset<int>::iterator iter;
    int k;
    public:
    KthLargest(int k_, vector<int> nums) {
        k = k_;

        for(int i = 0;i < nums.size();i++)
            data.insert(nums[i]);

        if(k > data.size()) {
            iter = data.end();
        } else {
            iter = data.begin();
            for(int i = 0;i < data.size() - k;i++){
                iter++;
            }
            printf("iter:%d\n", *iter);
        }
    }

    int add(int val) {
        data.insert(val);
        if(iter != data.end()) {
            if(*iter <= val) {
                iter++;
            }

            return *iter;
        } else if(k <= data.size()){
            iter = data.begin();
            for(int i = 0;i < data.size() - k;i++){
                iter++;
            }

            return *iter;
        }

        return -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
