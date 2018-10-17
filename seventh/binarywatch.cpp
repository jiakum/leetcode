
class Solution {
    public:
#define HOUR_LED (4)
#define MINUTE_LED (6)
#define TOTAL_LED (HOUR_LED + MINUTE_LED)
        void addTime(vector<int> &status, vector<string> &result) {
            int hour = 0, i, minute = 0;
            char num[16];

            for(i = 0;i < HOUR_LED;i++) {
                hour <<=  1;
                hour |= status[i];
            }
            for(i = HOUR_LED;i < TOTAL_LED;i++) {
                minute <<=  1;
                minute |= status[i];
            }

            if(hour >= 12 || minute >= 60)
                return;
            snprintf(num, sizeof(num), "%d:%02d", hour, minute);
            result.push_back(string(num));
        }
        void subSearch(vector<int> &status, int index, int num, vector<string> &result) {
            if(status.size() - index < num)
                return;
            if(num == 0) {
                addTime(status, result);
                return;
            } else if(index == status.size() || num <= 0) {
                return;
            }

            status[index] = 0;
            subSearch(status, index + 1, num, result);
            status[index] = 1;
            subSearch(status, index + 1, num - 1, result);
            status[index] = 0;
        }
        vector<string> readBinaryWatch(int num) {
            vector<string> result;
            vector<int> status;
            int i;

            for(i = 0;i < TOTAL_LED;i++)
                status.push_back(0);

            subSearch(status, 0, num, result);

            return result;
        }
};
