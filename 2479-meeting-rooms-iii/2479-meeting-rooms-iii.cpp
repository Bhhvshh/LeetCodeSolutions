class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& m) {
        
        priority_queue<int,vector<int>,greater<int>> room;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> meet;
        long  ans = 0;
        vector<long> fr(n);
        for(int i = 0;i<n;i++)
          room.push(i);

        sort(m.begin(),m.end());

        for(auto x:m){
            while(!meet.empty() && meet.top().first<=x[0]){
                room.push(meet.top().second);
                meet.pop();
            }

            long long  end = x[1];
            if(room.empty()){
                room.push(meet.top().second);
                // extra+=meet.top().first;
                end = meet.top().first+ (x[1] - x[0]);
                meet.pop();


            }
            int assign = room.top();
            room.pop();

            ans = max(++fr[assign],ans);


            
            meet.push({end,assign});
            
        }


        for(int i = 0;i<n;i++) if(fr[i]==ans) return i;

        return -1;

    }
};