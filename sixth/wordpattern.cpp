
class Solution {
    public:
        bool wordPattern(string pattern, string str) {
            stringstream ss(str);
            set<string> s;
            int num= 0;
            string temp;
            unordered_map<char, string> mp;
            for(int i= 0; i< pattern.size(); i++){
                getline(ss, temp, ' ');
                if(mp.find(pattern[i])== mp.end()){
                    mp[pattern[i]]= temp;
                    s.insert(temp);
                    if(s.size()!= ++num)
                        return false;
                }
                else if(mp[pattern[i]]!= temp)
                    return false;
            }
            if(getline(ss, temp, ' '))
                return false;
            return true;
        }
};
