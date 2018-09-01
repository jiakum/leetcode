class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> sortnums(nums);
        int size = nums.size(), i, j, k, delta = 0x7fffffff;
        
        if(size <= 3)
            return nums[0] + nums[1] + nums[2];
        
        sort(sortnums.begin(), sortnums.end());
        for(i = 0;i < size - 2;i++) {
            int ni = sortnums[i];
            if(i > 0 && ni == sortnums[i - 1])
                continue;
            for(j = i + 1, k = size -1;j < k;){
                int nj = sortnums[j];
                int nk = sortnums[k];
                int value = ni + nj + nk - target;
                
                if(value == 0) {
                    return target;
                } else if(value > 0) {
                    k --;                
                } else {
                    j++;
                }
                
                if(abs(value) < abs(delta))
                    delta = value;
            }
        }
        
        return delta + target;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().threeSumClosest(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}