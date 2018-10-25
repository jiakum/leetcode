
class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            map<int, int> lmap;
            map<int, int>::iterator iter;

            lmap[5] = 0;
            lmap[10] = 0;
            lmap[20] = 0;
            for(int i = 0;i < bills.size();i++) {
                int n = bills[i];

                switch(n)
                {
                    case 5:
                        iter = lmap.find(5);
                        iter->second++;
                        break;
                    case 10:
                        iter = lmap.find(5);
                        if(--iter->second < 0)
                            return false;
                        iter = lmap.find(10);
                        iter->second++;
                        break;
                    case 20: 
                        {
                            int five;

                            iter = lmap.find(10);
                            if(iter->second > 0) {
                                iter->second--;
                                five = 1;
                            } else {
                                five = 3;
                            }

                            iter = lmap.find(5);
                            iter->second -= five;
                            if(iter->second < 0)
                                return false;
                        }
                        break;
                }
            }

            return true;
        }
};
