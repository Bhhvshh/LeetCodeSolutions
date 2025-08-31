class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans;
        unordered_map<int,bool> umap;
        for(auto x:friends) umap[x] = true;

        for(auto x:order)
          if(umap[x]) ans.push_back(x);

        return ans;
        
    }
};