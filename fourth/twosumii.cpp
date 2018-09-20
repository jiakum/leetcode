
class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            map<int, int> imap;
            map<int, int>::iterator iter;
            vector<int> result;
            int i, size = numbers.size();

            if(size < 2)
                return result;

            for(i = 0;i < size;i++) {
                imap[numbers[i]] = i;
            }        
            for(i = 0;i < size;i++) {
                int n = target - numbers[i];
                iter = imap.find(n);
                if(iter == imap.end() || iter->second == i)
                    continue;

                result.push_back(i + 1);
                result.push_back(iter->second + 1);
                break;
            }

            return result;
        }
};

class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            vector<int> result;
            int i, size = numbers.size();

            if(size < 2)
                return result;

            int left = 0, right = size - 1;      
            while(left < right) {
                int n = numbers[left] + numbers[right];

                if(n == target) {
                    result.push_back(left + 1);
                    result.push_back(right + 1);

                    break;
                }

                if(n > target)
                    right--;
                else
                    left++;

            }

            return result;
        }
};
