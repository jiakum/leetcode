
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <vector>

using namespace std;

static inline int COUNT_AREA(int il, int iu, vector<int>& height) 
{ 
    int mh = min(height[il], height[iu]); 

    return mh * (iu - il);
}

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int size = height.size();
            int il = 0, iu = size - 1, max = 0, tmp;

            if(size < 2)
                return max;

            while(il < iu) {
                tmp = COUNT_AREA(il, iu, height);
                if(tmp > max) {
                    max = tmp;
                    continue;
                }

                if(height[iu] < height[il])
                    iu--;
                else
                    il++;
            }

            return max;
        }
};

int main()
{
    Solution sol;
    vector<int> height = {1,3,2,5,25,24,5};

    printf("max area :%d\n", sol.maxArea(height));
    return 0;
}
