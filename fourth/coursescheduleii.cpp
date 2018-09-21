
class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
            if(canFinish(numCourses, prerequisites))
                return path;
            else
                return vector<int> ();
        }
    private:
        vector<vector<int>> prerequire;
        vector<bool> finished;
        vector<int> path;
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
            path.push_back(course);

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
                int key = p.first, dep = p.second;

                vector<int> &vi = prerequire[key];
                vi.push_back(dep);
            }

            vector<int> history(numCourses, 0);
            for(i = 0;i < numCourses;i++) {
                if(prerequire[i].empty()) {
                    path.push_back(i);
                    finished[i] = true;
                    break;
                }
            }
            if(path.empty())
                return false;
            vector<int> result = path;
            for(i = 0;i < numCourses;i++) {
                if(finished[i])
                    continue;
                path.clear();
                if(checkOneCourse(history, i) == false)
                    return false;
                for(int j = 0;j < path.size();j++)
                    result.push_back(path[j]);
            }
            path = result;

            return true;
        }
};
