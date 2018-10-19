
class Solution {
    public:
        vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
            vector<string> result, least;
            unordered_map<string, int> data;
            unordered_map<string, int>::iterator iter;
            int index = INT_MAX;

            for(int i = 0;i < list1.size();i++) {
                string &str = list1[i];

                data[str] = i;
            } 
            for(int i = 0;i < list2.size();i++) {
                string &str = list2[i];

                iter = data.find(str);
                if(iter != data.end()) {
                    if(i + iter->second > index) {
                        continue;
                    } else if( i + iter->second == index) {
                        least.push_back(str);
                    } else {
                        least.clear();
                        least.push_back(str);
                        index = iter->second + i;
                    }
                }
            }

            return least;
        }
};
