
class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            vector<int> nums(gas);
            int maxv;
            int size = gas.size(), total = 0;
            for(int i = 0;i < size;i++)
            {
                nums[i] = gas[i] - cost[i];
                total += nums[i];
            }

            if(total < 0)
                return -1;

            int result = 0;
            total = 0;
            for(int i = 0;i < size;i++)
            {
                total += nums[i];
                if(total < 0) {
                    total = 0;
                    result = i + 1;
                }
            }
            return result;
        }
};
