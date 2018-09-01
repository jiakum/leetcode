static const char *dtoa[] = 
    {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

static void append_al(vector<string> &result, string &s, string digits)
{
    string snew;
    int i, j;
    
    if(digits.size() <= 1){
        
        char c = digits[0];

        if(c <= '1' || c > '9')
            return;

        c = c - '0';
        j = 0;
        do {
            snew = s;
            snew.push_back(dtoa[c][j]);
            result.push_back(snew);
        } while(dtoa[c][++j] != '\0');
        return;
    }
    
    char c = digits[0];

    if(c < '1' || c > '9'){
        append_al(result, snew, digits.substr(1, digits.size() - 1));
        return;
    }

    c = c - '0';
    j = 0;
    do {
        snew = s;
        snew.push_back(dtoa[c][j]);
        append_al(result, snew, digits.substr(1, digits.size() - 1));
    } while(dtoa[c][++j] != '\0');

}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string s;
        
        append_al(result, s, digits);
        
        return result;
    }
};

