class Solution {
public:
    int findLHS(vector<int>& nums) {

        unordered_map<int,int> umap;
        int ans = 0;

        for(auto x:nums) umap[x]++;

        for(auto x:nums)
          if(umap[x+1]) ans = max(ans,umap[x+1]+ umap[x]);

        return ans;
        
    }
};