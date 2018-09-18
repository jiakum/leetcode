
class Solution {
    inline bool onlyOneDefer(string &first, string &second) {
        int i, defers = 0;

        for(i = 0;i < first.size();i++) {
            if(first[i] != second[i]) {
                defers++;
                if(defers > 1)
                    return false;
            }
        }

        return true;
    }
    public:
    int maxLadderLength(int start, int end, 
            vector<string>& wordList) {
        int i, index = start, size = wordList.size();
        int from[size];
        queue<int> inlist;

        for(i = 0;i < size;i++)
            from[i] = -1;
        inlist.push(index);
        int len = 0;

        while(!inlist.empty()) {
            index = inlist.front();
            inlist.pop();
            vector<int> &vi = dp[index];

            for(int i = 0;i < vi.size();i++) {
                int j = vi[i];
                if(from[j] == -1) {
                    from[j] = index;
                    inlist.push(j);
                }
            }
        }

        len = 0;
        index = from[end];
        while(index != start) {
            if(index == -1)
                return 0;
            len++;
            index = from[index];
        }

        return len + 2;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int i, j, size, n;
        int end = -1, start = -1;
        vector<string> copied = wordList;
        size = copied.size();

        n = beginWord.size();
        if(n == 0 || size == 0)
            return 0;

        for(i = size - 1;i >= 0;i--) {
            if(endWord == copied[i]) {
                end = i;
            } else if(beginWord == copied[i]) {
                start = i;
            }

            if(start != -1 && end != -1)
                break;
        }

        if(end == -1)
            return 0;

        if(n == 1 || onlyOneDefer(beginWord, endWord))
            return 2;

        if(start == -1) {
            copied.push_back(beginWord);
            start = size;
            size += 1;
        }

        dp.clear();
        for(i = 0;i < size;i++) {
            vector<int> vi;
            string &str = copied[i];
            for(j = 0;j < size;j++) {
                if(i == j)
                    continue;
                if(onlyOneDefer(copied[j], str)) {
                    vi.push_back(j);                  
                }
            }

            dp.push_back(vi);
        }

        return maxLadderLength(start, end, copied);
    }
    private:
    vector<vector<int>> dp;
};
