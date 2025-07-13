class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr) return;

        if (rank[xr] < rank[yr]) {
            parent[xr] = yr;
        } else if (rank[xr] > rank[yr]) {
            parent[yr] = xr;
        } else {
            parent[yr] = xr;
            rank[xr]++;
        }
    }

    int countComponents() {
        unordered_set<int> roots;
        for (int i = 0; i < parent.size(); ++i) {
            roots.insert(find(i));
        }
        return roots.size();
    }
};

class Solution {
public:
    bool can(int n,vector<vector<int>> &v,int &k,int &mid){
        DSU d(n);
        for(auto &x:v){
            if(x[2]>mid){
                d.unite(x[0],x[1]);
            }
        }

        return d.countComponents()>=k;
        
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int max_w = 0;
    //     sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b) {
    //     return a[2] > b[2];  // '>' gives non-increasing order
    // });

        for(auto &x:edges) max_w = max(max_w,x[2]);
        

        int l = 0, r = max_w;
        int result = -1;

        while(l<=r){
            int mid = l + ((r-l)>>1);

            if(can(n,edges,k,mid)){

                result = mid;
                r = mid -1;
                
            }
            else{
                l = mid + 1;
                
            }
        }


        return result;
        
    }
};