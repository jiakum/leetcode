class Solution {
    public:
        int findRadius(vector<int>& houses, vector<int>& heaters) {
            int i, last = 0, size = heaters.size(), result = 0;

            sort(houses.begin(), houses.end());
            sort(heaters.begin(), heaters.end());
            for(i = 0;i < houses.size();i++) {
                for(int j = last + 1;j < size;j++) {
                    if(abs(heaters[j] - houses[i]) <= abs(heaters[last] - houses[i])) {
                        last = j;
                        continue;
                    } else {
                        break;
                    }
                }

                result = max(result, abs(heaters[last] - houses[i]));
            }

            return result;
        }
};
