

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
        vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
            vector<Interval> result(intervals);
            Interval pos;
            int i, j, found;

            found = 0;
            for(i = 0;i < result.size();i++) {
                if(newInterval.start <= result[i].start || newInterval.start <= result[i].end) {
                    if(result[i].end <= newInterval.start) {
                        found = 1;
                    } else if(newInterval.end >= result[i].start) {
                        found = 1;
                    }

                    if(found) {
                        pos = join_interval(result[i], newInterval);
                        result[i] = pos;      
                    } else {
                        result.insert(result.begin() + i, newInterval);
                        found = 1;
                        break;
                    }

                    for(j = i + 1;j < result.size();j++) {
                        Interval inter = result[i]; 
                        Interval rinter = result[j];

                        if(overlapped(inter, rinter)) {                
                            result[i] = join_interval(inter, rinter);
                            result.erase(result.begin() + j);
                            j--;
                            found = 1;
                            continue;;
                        } else {
                            break;
                        }
                    }
                    found = 1;
                    break;
                }
            }
            if(found == 0)
                result.push_back(newInterval);

            return result;
        }

        static bool overlapped(Interval &inter1, Interval &inter2)
        {
            if(inter1.start > inter2.end)
                return false;
            if(inter2.start > inter1.end)
                return false;
            return true;
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
};
