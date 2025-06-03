class DSU {
    
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        // size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (b < a)
                swap(a, b);
            parent[b] = a;
           
        }
    }

    vector<int> getSetNumbers() {
        unordered_map<int, int> rootToSetId;
        vector<int> setId(parent.size());
        int currentSet = 0;

        for (int i = 0; i < parent.size(); i++) {
            int root = find(i);
            if (rootToSetId.find(root) == rootToSetId.end()) {
                rootToSetId[root] = currentSet++;
            }
            setId[i] = rootToSetId[root];
        }
        return setId;
    }
};


class Solution {
public:

    string smallestEquivalentString(string s1, string s2, string baseStr) {

        int n =s1.size();
        DSU dsu(26);
        for(int i =0;i<n;i++){
            dsu.unite(s1[i]-'a',s2[i]-'a');
        }

        unordered_map<int,vector<int>> umap;

        for(int i = 0;i<26;i++){
            int par = dsu.find(i);
            umap[par].push_back(i);

        }
         vector<char> smallestmap(26);
        for(auto &x:umap){
            int min_ =INT_MAX;
            for(auto y:x.second)
                   min_ = min(min_,y);
            // cout << (char)('a'+min_)<< endl;
            for(auto y:x.second){
                smallestmap[y] = 'a'+min_;
            }
        }

        string ans = "";

        for(auto x:baseStr){
            ans.push_back(smallestmap[x-'a']);
        }

        return ans;
        
    }
};