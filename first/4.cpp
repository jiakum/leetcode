
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int imax, imin, i, j, m, n, halflen;

            m = nums1.size();
            n = nums2.size();

            if(m <= n) {
                imin = 0;imax = m;
                halflen = (m + n + 1) / 2;
                while(imin <= imax) {
                    i = (imin + imax) / 2;
                    j = halflen - i;

                    if(i < imax && nums2[j - 1] > nums1[i]) {
                        imin = i + 1;
                    } else if(i > imin && nums1[i - 1] > nums2[j]) {
                        imax = i - 1;
                    } else {
                        int maxleft = 0;

                        if(i == 0)
                            maxleft = nums2[j - 1];
                        else if(j == 0)
                            maxleft = nums1[i - 1];
                        else
                            maxleft = max(nums2[j - 1], nums1[i - 1]);

                        if((m + n) & 0x01)
                            return maxleft;

                        int minright;
                        if(i == m)
                            minright = nums2[j];
                        else if(j == n)
                            minright = nums1[i];
                        else
                            minright = min(nums2[j], nums1[i]);

                        return ((double)maxleft + minright) / 2;
                    }
                }
            } else {
                imin = 0;imax = n;
                halflen = (m + n + 1) / 2;
                while(imin <= imax) {
                    i = (imin + imax) / 2;
                    j = halflen - i;

                    if(i < imax && nums1[j - 1] > nums2[i]) {
                        imin = i + 1;
                    } else if(i > imin && nums2[i - 1] > nums1[j]) {
                        imax = i - 1;
                    } else {
                        int maxleft = 0;

                        if(i == 0)
                            maxleft = nums1[j - 1];
                        else if(j == 0)
                            maxleft = nums2[i - 1];
                        else
                            maxleft = max(nums1[j - 1], nums2[i - 1]);

                        if((m + n) & 0x01)
                            return maxleft;

                        int minright;
                        if(i == n)
                            minright = nums1[j];
                        else if(j == m)
                            minright = nums2[i];
                        else
                            minright = min(nums1[j], nums2[i]);

                        return ((double)maxleft + minright) / 2;
                    }
                }
            }

            return 0.0;
        }
};


int main()
{
    class Solution sol;
    vector<int> va = {1 ,2}, vb = {3, 4};

    printf("median:%lf\n", sol.findMedianSortedArrays(vb, va));
    printf("median:%lf\n", sol.findMedianSortedArrays(va, vb));


    return 0;
}
