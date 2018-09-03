
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

static inline void insert_new_triple(vector<vector<int>> &result, int ni, int nj, int nk)
{
    vector<int> vi;

    vi.push_back(ni);
    vi.push_back(nj);
    vi.push_back(nk);

    result.push_back(vi);
}

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            vector<int> sorted(nums);
            int size = nums.size(), i, j, k;

            if(size <= 2)
                return result;

            sort(sorted.begin(), sorted.end());
            for(i = 0;i < size - 2;i++) {
                int ni = sorted[i];
                if(ni > 0)
                    break;
                else if(i > 0 && ni == sorted[i - 1])
                    continue;

                for(j = i + 1, k = size - 1;j < k;) {
                    int nj = sorted[j];
                    int nk = sorted[k];
                    int value = ni + nj + nk;
                    if(value == 0) {
                        insert_new_triple(result, ni, nj, nk);

                        do  {
                            j++;
                        } while(nj == sorted[j] && j < k);
                        do {
                            k--;
                        } while(nk == sorted[k] && j < k);
                    } else if(value > 0) {
                        k--;
                    } else {
                        j++;
                    }
                }
            }

            return result;
        }
};

int main()
{
    Solution sol;
    vector<int> nums = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<vector<int>> result;
    int i;

    result = sol.threeSum(nums);
    for(i = 0;i < (int)result.size();i++) {
        cout << result[i][0] << " " <<  result[i][1] << " " << result[i][2] << endl;
    }

    return 0;
}
