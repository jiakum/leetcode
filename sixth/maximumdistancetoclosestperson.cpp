
class Solution {
    public:
        int maxDistToClosest(vector<int>& seats) {
            int zero = 0, result = 0, i, size = seats.size();
            pair<int, int> start = pair<int, int>(1, 0);

            for(i = 0;i < size;i++) {
                if(seats[i] == 0) {
                    zero++;
                    if(start.first)
                        start.second++;

                    result = max(result, zero);
                } else {
                    zero = 0;
                    start.first = 0;
                }
            }

            printf("zero:%d, result:%d, start:%d\n", zero, result, start.second);
            result = (result + 1) / 2;
            if(result < zero || result < start.second)
                return max(zero, start.second);

            return result;
        }
};
