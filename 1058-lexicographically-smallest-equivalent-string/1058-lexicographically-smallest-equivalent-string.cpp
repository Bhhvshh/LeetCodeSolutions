class DSU {
    
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
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

  
};


class Solution {
public:

    string smallestEquivalentString(string s1, string s2, string baseStr) {

        int n =s1.size();
//initialize dsu with size 26 
        DSU dsu(26);
  //unite equivalent character
        for(int i =0;i<n;i++)
            dsu.unite(s1[i]-'a',s2[i]-'a');
        

// create groups of disjoint sets and find smallest charcter from it to represent it.
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
           
            for(auto y:x.second){
                smallestmap[y] = 'a'+min_;
            }
        }

        string ans = "";

        for(auto x:baseStr)
            ans.push_back(smallestmap[x-'a']);
        

        return ans;
        
    }
};