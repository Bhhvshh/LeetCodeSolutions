class Solution {
public:

long long  dfs(int u,int par,vector<vector<int>> &g,vector<int>& cost,int &ans,vector<long long>& pathtoleaf){
    
       long long max_ = 0;

        for(auto v:g[u]){
            if(v==par) continue;
            pathtoleaf[v] = dfs(v,u,g,cost,ans,pathtoleaf);
            // children.push_back(tmp);
            max_ = max(max_,pathtoleaf[v]);

        }
        for(auto v:g[u]) if(v!=par && pathtoleaf[v]!=max_) ans++;

        return cost[u] + max_;



    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {

        vector<vector<int>> graph(n);
        vector<long long> ptol(n);
        for(auto x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }

        int ans = 0;

        dfs(0,-1,graph,cost,ans,ptol);

        return ans;
        
    }
};