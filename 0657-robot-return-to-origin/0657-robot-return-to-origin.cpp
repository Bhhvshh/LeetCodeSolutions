class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;

        for(auto c: moves){
            x += (c == 'R')  ? 1 : ((c == 'L') ? -1 : 0);
            y += (c == 'D') ? 1 : ((c == 'U') ? -1 : 0);
        }

        return x == 0 && y == 0;
    }
};