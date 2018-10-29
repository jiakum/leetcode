
class Solution {
    public:
        bool judgeCircle(string moves) {
            int i, x = 0, y = 0, size = moves.size();

            for(i = 0;i < size;i++) {
                char c = moves[i];
                switch(c) {
                    case 'U':
                        y += 1;
                        break;
                    case 'D':
                        y -= 1;
                        break;
                    case 'R':
                        x += 1;
                        break;
                    case 'L':
                        x -= 1;
                        break;
                }
            }

            return x == 0 && y == 0;
        }
};
