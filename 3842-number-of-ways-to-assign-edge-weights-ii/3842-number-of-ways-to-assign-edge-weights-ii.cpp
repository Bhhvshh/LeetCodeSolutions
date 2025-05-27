class Solution {
public:
    static const int MAXN = 1e5 + 5;
int timer = 0;
vector<vector<int>> adj;
vector<int> euler, depth, first;
 int st[20][2 * MAXN]; // Sparse table for RMQ
int logTable[2 * MAXN];
long long mod = 1e9 + 7;

//euler tour + RMQ
void dfs(int node, int parent, int d) {
    first[node] = euler.size();
    euler.push_back(node);
    depth.push_back(d);

    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node, d + 1);
            euler.push_back(node);
            depth.push_back(d);
        }
    }
}

// Build sparse table
void buildSparseTable() {
    int n = depth.size();
    for (int i = 0; i < n; ++i)
        st[0][i] = i;

    for (int k = 1; (1 << k) <= n; ++k) {
        for (int i = 0; i + (1 << k) <= n; ++i) {
            int x = st[k - 1][i];
            int y = st[k - 1][i + (1 << (k - 1))];
            st[k][i] = (depth[x] < depth[y]) ? x : y;
        }
    }

    // Precompute logs
    logTable[1] = 0;
    for (int i = 2; i < 2 * MAXN; ++i)
        logTable[i] = logTable[i / 2] + 1;
}

// Query LCA of u and v
int lca(int u, int v) {
    int left = first[u];
    int right = first[v];
    if (left > right) swap(left, right);
    int len = right - left + 1;
    int k = logTable[len];

    int x = st[k][left];
    int y = st[k][right - (1 << k) + 1];
    return (depth[x] < depth[y]) ? euler[x] : euler[y];
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
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        adj.resize(n+1);
        for (int i = 0; i < n - 1; ++i) {
       int u = edges[i][0];
       int v = edges[i][1];
        // edges
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    first.resize(n + 1);
    dfs(1, -1, 0);        
    buildSparseTable();
    
    


     queue<int> q;
    q.push(1);
    vector<int> level(n+1,-1);
    level[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (level[v] == -1) { 
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }

    vector<int> ans;

    for(auto x:queries){
        int lcParent = lca(x[0],x[1]);
        // cout <<lcParent<< endl;
        // cout << level[x[1]] << endl;
        int pathLength = level[x[0]] + level[x[1]] - level[lcParent] - level[lcParent];
        cout << pathLength << endl;
        if(pathLength>0) ans.push_back(myPow(2,pathLength - 1));
        else ans.push_back(0);

    }


    return ans;

      
    }
};