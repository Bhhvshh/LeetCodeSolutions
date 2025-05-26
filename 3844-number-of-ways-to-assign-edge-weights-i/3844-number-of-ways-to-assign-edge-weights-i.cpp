class Solution {
public:
long long mod = 1e9 + 7;
void dfs(int node, int parent, int depth, const vector<vector<int>>& adjList,            int&    maxDepth) {
    maxDepth = max(maxDepth, depth);
    for (int neighbor : adjList[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, depth + 1, adjList, maxDepth);
        }
    }
}
   long long myPow(long long x, long long n) {
    if (n == 0) return 1;

    x = x % mod;
    

    if (n % 2 == 0) {
        long long half = myPow((x * x) % mod, n / 2);
        return half % mod;
    } else {
        return (x * myPow(x, n - 1)) % mod;
    }
}

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+ 1;
        vector<vector<int>> adj(n+1);

        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        int maxDepth = 0;
        dfs(1, -1, 0, adj, maxDepth);

        long long ans = (myPow(2,maxDepth-1)); 
        // long long result = 0;
        // long long rem =myPow(2,(n - 1 - maxDepth))%mod;
        // cout << rem << endl;
          
        // for(long long i =0;i<ans;i++){
        //     result = (result + rem)%mod;

        // }

        return ans;
    }
};