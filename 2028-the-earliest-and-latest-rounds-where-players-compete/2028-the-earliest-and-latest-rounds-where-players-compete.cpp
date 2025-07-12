#include <cstdint>
class Solution {
public:
    unordered_map<int, bool> umap;

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
       
       int players = (1 << n) -1;
        int ear = INT_MAX;
        int lat = INT_MIN;
       int curr = 0;
        helper(0, n, 1, firstPlayer, secondPlayer, ear, lat, curr, players);
        return {ear, lat};
    }

    void helper(int id, int n, int round, int &fp, int &sp, int &ear, int &lat, int &curr, int &player) {
        if (n == 1) return;

        if (id == 0 && areOpponents(player, fp, sp)) {
            ear = min(ear, round);
            lat = max(lat, round);
            return;
        }

        if (n == 2) return;

        if (id == (n - 1) / 2 + 1) {
           if(umap[curr]) return;
           umap[curr] = true;

            int nextround = curr;
            
            int tmp = 0;
            helper(0, (n+1)/2, round + 1, fp, sp, ear, lat, tmp, nextround);
            return;
        }
       int a = -1, b = -1;
int count = 0;
for (int i = 0; i < 32; ++i) {
    if (player & (1 << i)) {
        if (count == id) a = i + 1;
        if (count == n - id - 1) b = i + 1;
        count++;
    }
}

        if (a == fp || a == sp) {
            curr|= (1<<(a-1));
            helper(id + 1, n, round, fp, sp, ear, lat, curr, player);
            curr^=(1<<(a-1));
        } else if (b == fp || b == sp) {
            curr|= (1<<(b-1));
            helper(id + 1, n, round, fp, sp, ear, lat, curr, player);
            curr^=(1<<(b-1));
        } else {
            curr|= (1<<(a-1));
            helper(id + 1, n, round, fp, sp, ear, lat, curr, player);
            curr^=(1<<(a-1));

           curr|= (1<<(b-1));
            helper(id + 1, n, round, fp, sp, ear, lat, curr, player);
            curr^=(1<<(b-1));
        }
    }

    bool areOpponents(int &player, int &fp, int &sp) {
        
        vector<uint8_t> players;
        for(int i = 0;i<=28;i++){
            if(player &(1<<i)){
                players.push_back(i+1);
            }
        }
        int n = players.size();
        for (int i = 0; i <= (n - 1) / 2; i++) {
            if ((players[i] == fp && players[n - i - 1] == sp) || 
                (players[i] == sp && players[n - i - 1] == fp)) 
                return true;
        }
        return false;
    }

    // string makeKey(const vector<uint8_t> &v, int round) {
    //     string res;
    //     for (int x : v) {
    //         res += to_string(x) + ",";
    //     }
    //     res += "#" + to_string(round);
    //     return res;
    // }
};
