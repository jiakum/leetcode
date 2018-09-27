
class Solution {
    public:

        static bool HdescendingKascending(pair<int, int>& a, pair<int, int> b)
        {
            // return true when you want to put a in front of b.
            if (a.first > b.first) 
            {
                // tallest first. "h" descending
                return true;
            }
            else
                if (a.first == b.first && a.second < b.second)
                {
                    // for same height, put people with smaller "k" first. "k" ascending
                    return true;
                }

            return false;                
        }
        vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
            vector<pair<int, int>> result;

            sort(people.begin(),people.end(), HdescendingKascending);

            //place in k's location
            vector<pair<int, int>> temp;

            for(auto p :  people)
                temp.insert(temp.begin() + p.second, p);

            return temp;
        }

};
