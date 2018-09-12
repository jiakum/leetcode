
class Solution {
    public:
        string simplifyPath(string path) {
            string result;
            int i, size = path.size(), ptr = 0;

            if(size == 0)
                return result;

            char s[size + 2];
            for(i = 0;i < size;i++) {
                char c = path[i];
                switch(c)
                {
                    case '/':
                        s[ptr++] = c;
                        while(path[i + 1] == '/') i++;
                        break;
                    case '.':
                        if(path[i + 1] == '.' && (path[i + 2] == '/' || path[i + 2] == '\0')) {
                            i += 2;
                            while(path[i + 1] == '/')
                                i++;

                            if(ptr > 1) ptr--;

                            while(s[ptr - 1] != '/') ptr--;
                        } else if(path[i + 1] == '/') {
                            while(path[i + 1] == '/')
                                i++;
                        } else if(path[i + 1] != '\0') {
                            while(path[i] && path[i] != '/') {
                                s[ptr++] = path[i];
                                i++;
                            }
                            i--;
                        }
                        break;
                    default:
                        s[ptr++] = c;
                        break;
                }
            }

            if(s[ptr - 1] == '/' && ptr > 2)
                ptr--;
            s[ptr] = '\0';

            result = s;
            return result;
        }
};
