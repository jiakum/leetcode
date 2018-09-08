
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    public:
        static bool overlapped(Interval &inter1, Interval &inter2)
        {
            if(!(inter1.start < inter2.start || inter1.start > inter2.end))
                return true;
            if(!(inter1.end < inter2.start || inter1.end > inter2.end))
                return true;
            return false;
        }
        Interval join_interval(Interval &inter1, Interval &inter2)
        {
            int start = inter1.start, end = inter1.end;

            if(start > inter2.start)
                start = inter2.start;
            if(end < inter2.end)
                end = inter2.end;

            return Interval(start, end);
        }
        vector<Interval> merge(vector<Interval>& intervals) {
            vector<Interval> result;
            int size = intervals.size(), i, j;

            for(i = 0;i < size;i++) {
                Interval inter = intervals[i];
                int found = 0;
                for(j = 0;j < result.size();j++) {
                    Interval &rinter = result[i];

                    if(overlapped(inter, rinter)) {
                        result[j] = join_interval(inter, rinter);
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    result.push_back(inter);
            }
            return result;
        }
};
