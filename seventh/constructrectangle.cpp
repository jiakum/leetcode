
class Solution {
    public:
        vector<int> constructRectangle(int area) {
            vector<int> result;
            int n = sqrt(area);

            while(area % n) {
                n++;
            }

            if(n < area / n)
                n = area / n;

            result.push_back(n);
            result.push_back(area / n);

            return result;
        }
};
