
class Solution {
    public:
        bool inRect(vector<int> &rec, int x1, int x2, int y) {
            if(y <= rec[1] || y >= rec[3] || x1 >= rec[2] || x2 <= rec[0])
                return false;
            else
                return true;
        }
        bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
            if(rec1 == rec2) {
                return true;
            }

            if(inRect(rec1, rec2[0], rec2[2], rec2[1]) || inRect(rec1, rec2[0], rec2[2], rec2[3])
                    || inRect(rec2, rec1[0], rec1[2], rec1[1]) || inRect(rec2, rec1[0], rec1[2], rec1[3]))
                return true;

            return false;
        }
};
