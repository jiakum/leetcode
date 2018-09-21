
class Solution {
    vector<vector<int>> prerequire;
    vector<int> finished;
    public:
    bool checkOneCourse(vector<int> &history, int course) {
        if(finished[course])
            return true;

        history[course] = 1;
        vector<int> &vi = prerequire[course];
        for(int i = 0;i < vi.size();i++) {
            int n = vi[i];

            if(finished[n])
                continue;
            if(history[n])
                return false;

            if(checkOneCourse(history, n) == false)
                return false;
        }
        history[course] = 0;

        finished[course] = true;
        return true;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int i, size = prerequisites.size();

        finished.clear();
        prerequire.clear();
        for(i = 0;i < numCourses;i++) {
            vector<int> vi;
            finished.push_back(0);
            prerequire.push_back(vi);
        }

        for(i = 0;i < size;i++) {
            pair<int, int> &p = prerequisites[i];
            int key = p.second, dep = p.first;

            vector<int> &vi = prerequire[key];
            vi.push_back(dep);
        }

        vector<int> history(numCourses, 0);
        for(i = 0;i < numCourses;i++) {
            if(finished[i])
                continue;
            if(checkOneCourse(history, i) == false)
                return false;
        }

        return true;
    }
};
