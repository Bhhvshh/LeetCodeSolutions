class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();

        vector<vector<int>>adj(n);
        queue<int> q;
        vector<int> inDeg(n);

        for(int i =0;i<n-1;i++){
            if(ratings[i]<ratings[i+1]){
                adj[i].push_back(i+1);
                inDeg[i+1]++;
            }
            else if(ratings[i]>ratings[i+1]){
                adj[i+1].push_back(i);
                inDeg[i]++;
            }
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        if(inDeg[n-1]==0) q.push(n-1);

        int candy =1;
        int ans =0;

        while(!q.empty()){
            int level = q.size();

            for(int i =0;i<level;i++){
                ans+=candy;
                int u =q.front();q.pop();
                // cout<< u << " "<<candy<<endl;

                for(auto v:adj[u]){
                    if(--inDeg[v]==0){
                        q.push(v);
                    }
                }
            }

            candy++;

        }

        return ans;
        
    }
};