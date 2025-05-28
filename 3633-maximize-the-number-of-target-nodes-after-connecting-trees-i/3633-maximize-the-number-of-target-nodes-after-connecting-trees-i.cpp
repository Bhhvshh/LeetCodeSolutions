class Solution {
public:
 int bfsTargets(vector<vector<int>> &adj, int src, int k){
     if(k<1) return k+1;
    vector<int> visited(adj.size());
    queue<int> q;
    q.push(src);
    int target = 1;
   
    visited[src] =  1;
    int level = 0;
    while(level<k && !q.empty()){
        
        int levelSize = q.size();
        
        for(int i =0;i<levelSize;i++){
            int u = q.front(); q.pop();
            for(auto v:adj[u]){
                if(!visited[v]){
                    visited[v] = 1;
                    q.push(v);
                    target++;
                }
            }
        }
        level++;

    }

    return target;
   }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {

        int n = edges1.size(), m = edges2.size();
        vector<vector<int>> adj1(n+1);
        vector<vector<int>> adj2(m+1);

        for(auto x:edges1){
            adj1[x[0]].push_back(x[1]);
            adj1[x[1]].push_back(x[0]);
        }

        for(auto y:edges2){
            adj2[y[0]].push_back(y[1]);
            adj2[y[1]].push_back(y[0]);
        }

        int tree2Max = 0;

        for(int i =0;i<=m;i++){
            tree2Max = max(tree2Max,bfsTargets(adj2,i,k-1));

        }
        // cout << tree2Max<< endl;

        vector<int> ans(n+1);

        for(int i = 0;i<=n;i++){
            ans[i] = bfsTargets(adj1,i,k) + tree2Max;
        }


        return ans;


        
    }
};