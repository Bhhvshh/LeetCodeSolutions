const int VEC_SIZE = 6;

struct SegmentTree {
    int n;
    vector<vector<int>> tree;

    SegmentTree(const vector<vector<int>>& data) {
        n = data.size();
        tree.resize(4 * n, vector<int>(VEC_SIZE, 0));
        build(1, 0, n - 1, data);
    }

    // Build segment tree
    void build(int node, int l, int r, const vector<vector<int>>& data) {
        if (l == r) {
            tree[node] = data[l];
        } else {
            int mid = (l + r) / 2;
            build(2 * node, l, mid, data);
            build(2 * node + 1, mid + 1, r, data);
            for (int i = 0; i < VEC_SIZE; i++)
                tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
        }
    }

    // Public update method: 0-based index
    void update(int idx, int k, int val) {
        update(1, 0, n - 1, idx, k, val);
    }

    // Recursive update
    void update(int node, int l, int r, int idx, int k, int val) {
        if (l == r) {
            // Set all to 0 except k-th value
            for (int i = 0; i < VEC_SIZE; i++)
                tree[node][i] = (i == k ? val : 0);
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid)
                update(2 * node, l, mid, idx, k, val);
            else
                update(2 * node + 1, mid + 1, r, idx, k, val);

            // Recalculate all 5 values
            for (int i = 0; i < VEC_SIZE; i++)
                tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
        }
    }

    // Public query method: 0-based indexing
    int query(int ql, int qr, int k) {
        return query(1, 0, n - 1, ql, qr, k);
    }

    // Recursive query
    int query(int node, int l, int r, int ql, int qr, int k) {
        if (qr < l || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node][k];

        int mid = (l + r) / 2;
        int left = query(2 * node, l, mid, ql, qr, k);
        int right = query(2 * node + 1, mid + 1, r, ql, qr, k);

        return left + right;
    }
};
class Solution {
public:
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        vector<vector<int>> data;
        for(auto x:nums){
            vector<int> v(6);
            v[popcount_depth(x)] = 1;
            data.push_back(v);
        }
        SegmentTree st(data);
        vector<int> ans;

        for(auto &x:queries){
            if(x[0]==1){
                ans.push_back(st.query(x[1],x[2],x[3]));
                
                
            }
            else{
                int d = popcount_depth(x[2]);
                st.update(x[1],d,1);
                
            }
        }
        return ans;

        
        
    }

    int popcount_depth(long long x) {
    if (x == 1) return 0;
    long long next = __builtin_popcountll(x);
    return 1 + popcount_depth(next);
}
};