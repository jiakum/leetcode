
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
        vector<Interval> merge(vector<Interval>& intervals) {
            vector<Interval> result;
            int size = intervals.size(), i, j, found;

            for(i = 0;i < size;i++) {
                Interval inter = intervals[i];
                found = 0;
                for(j = 0;j < result.size();j++) {
                    Interval rinter = result[j];

                    if(overlapped(inter, rinter)) {
                        result[j] = join_interval(inter, rinter);
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    result.push_back(inter);
            }

            do {
                found = 0;
                for(i = 0;i < result.size();i++) {       
                    for(j = i + 1;j < result.size();j++) {
                        Interval inter = result[i]; 
                        Interval rinter = result[j];

                        printf("start:%d,end:%d\n", rinter.start, rinter.end);
                        if(overlapped(inter, rinter)) {                
                            result[i] = join_interval(inter, rinter);
                            result.erase(result.begin() + j);
                            j--;
                            found = 1;
                            break;;
                        }
                    }
                }
            } while(found);
            return result;
        }
};
