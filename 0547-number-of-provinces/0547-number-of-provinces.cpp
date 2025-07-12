class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

       int n = isConnected.size();
        vector<bool> visited(n);
        int count = 0;

        for(int i = 0;i<n;i++){
            if(visited[i]) continue;
            count++;
            visited[i] = true;
            dfs(i,isConnected,visited);


        }


        return count;



        
    }

    void dfs(int src,vector<vector<int>> &g,vector<bool> &v){


        for(int i = 0;i<g.size();i++){
            if(g[src][i] && !v[i]){
                v[i] = true;
                dfs(i,g,v);
            }
        }


    }
};