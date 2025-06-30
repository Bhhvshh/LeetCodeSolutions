class DSU {
    vector<int> parent, rank;

public:
    // Constructor
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; ++i)
            parent[i] = i; // Initially each node is its own parent
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    // Union by rank
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY)
            return false; // Already in same set

        // Union by rank
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

bool can(int m,vector<vector<int>> &g,DSU d,int k,int n){
    for(auto &x:g){
        if(d.find(x[0])==d.find(x[1])) continue;
        else if(x[2]>=m) d.unite(x[0],x[1]);
        else if(x[2]*2>=m  && k){
            d.unite(x[0],x[1]);
            k--;
        }
        else return false;
    }

    unordered_map<int,int> umap;
    int count = 0;

    for(int i= 0;i<n;i++){
        int par = d.find(i);
        if(umap[par]) continue;
            umap[par] = true;
            count++;
        
    }
    // cout << m << " " << (count) << endl;

    return count==1;
}
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int r = INT_MAX;
        int max_ = -1;
        for(auto &x:edges){
            if(x[3]) r = min(r,x[2]);
            else max_ = max(max_,x[2]);
        }
        int l = 0;
        if(max_!=-1 && r==INT_MAX) r = max_*2;
        int result = -1;

        vector<vector<int>> notMust;
        DSU dsu(n);

        for(auto &x:edges){
            if(x[3]) {if(dsu.find(x[0])!=dsu.find(x[1]))dsu.unite(x[0],x[1]); else return -1;}
            else{
                notMust.push_back({x[0],x[1],x[2]});
            }
        }
        sort(notMust.begin(),notMust.end(),[](const vector<int> &a,const vector<int> &b){ return a[2]>b[2];});


        while(l<=r){
            int mid = l + ((r-l)>>1);

            if(can(mid,notMust,dsu,k,n)){
                result = mid;
                l = mid + 1;
            }
            else r  = mid - 1;
        }


        return result;
        
    }
};