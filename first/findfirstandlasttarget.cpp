
class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> result;
            stack<int> slow, shigh;
            int size = nums.size(), i, j, start = size, end = -1;

            if(size == 0) {
                result.push_back(-1);
                result.push_back(-1);
                return result;
            } else if(size == 1) {
                if(target == nums[0]) {
                    result.push_back(0);
                    result.push_back(0);                
                } else {
                    result.push_back(-1);
                    result.push_back(-1);
                }
                return result;
            } 

            if(nums[0] == target) {
                start = 0;
                end = 0;
            }
            if(nums[size - 1] == target) {
                end = size - 1;
                if(start > end)
                    start = end;
            }

            i = 0; j = size - 1;
            while(1) {
                if(i >= j - 1) {
                    if(slow.empty())
                        break;

                    i = slow.top();
                    j = shigh.top();
                    slow.pop(); shigh.pop();
                }
                int half = (i + j) / 2;

                if(nums[half] > target) {
                    j = half;
                } else if(nums[half] < target) {
                    i = half;
                } else {
                    if(start > half)
                        start = half;
                    if(end < half)
                        end = half;
                    if(i == half || j == half)
                        continue;
                    slow.push(half);
                    shigh.push(j);
                    j = half;
                }
            }

            if(end == -1) {
                result.push_back(-1);
                result.push_back(-1);
            } else {
                result.push_back(start);
                result.push_back(end);
            }

            return result;
        }
};
