class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int p1 = 0,p2 = 0;
        int m = players.size(),n = trainers.size();

        int count = 0;

        while(p1<m && p2<n){
            count+=(players[p1]<=trainers[p2]);
            p1+=(players[p1]<=trainers[p2]);
            

            p2++;

        }

        return count;
        
    }
};