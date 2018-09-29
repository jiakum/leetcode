
class Solution {
    public:
        int repeatedStringMatch(string A, string B) {
            int i, size = A.size();

            if(size == 0)
                return -1;

            int n = B.size() / size + 2;
            string str;
            for(i = 0;i < n;i++)
                str.append(A);

            int pos = str.find(B);
            if(pos == string::npos)
                return -1;

            int total = pos + B.size();
            if(total <= (n - 2) * A.size())
                return n - 2;
            else if(total <= (n - 1) * A.size())
                return n - 1;
            else
                return n;
        }
};
