
class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int i, j, size = nums.size();

            if(size == 0)
                return 0;

            int result, zero = -1;

            result = nums[0];

            for(i = 1;i < size;i++) {
                int n = nums[i];
                if(n < 0) {
                    int m = n, minus = m;
                    for(j = i - 1;j >= zero && j >= 0;j--) {
                        m *= nums[j];
                        if(minus < m)
                            minus = m;
                    }
                    if(n < minus)
                        n = minus;
                }  else if(n > 0) {
                    int m = n, minus = m;
                    for(j = i - 1;j >= zero && j >= 0;j--) {
                        m *= nums[j];
                        if(minus < m)
                            minus = m;
                    }
                    if(n < minus)
                        n = minus;
                } else {
                    zero = 0;
                }

                if(result < n)
                    result = n;
            }

            return result;
        }
};

class Solution {
    public:
        inline int maximum(const int& a,const int& b,const int& c) {
            return a>b?(a>c?a:c):(b>c?b:c);
        }

        inline int minimum(const int& a,const int& b,const int& c) {
            return a<b?(a<c?a:c):(b<c?b:c);
        }
        int maxProduct(vector<int>& nums) {
            //Making two dp arrays to store the maximum postive product and minimum negative product at each point
            int size = nums.size();
            int pos[size],neg[size];

            //Initialize to first term
            pos[0] = nums[0];
            neg[0] = nums[0];
            int ans = nums[0];

            //The positive array tries toget the max product while the negative array tries to get the least
            for(int i=1; i<size; i++) 
            {
                pos[i] = maximum(nums[i], pos[i-1]*nums[i],neg[i-1]*nums[i]); 
                neg[i] = minimum(nums[i], pos[i-1]*nums[i],neg[i-1]*nums[i]);

                ans = max(ans, pos[i]);
            }

            return ans;
        }
};
