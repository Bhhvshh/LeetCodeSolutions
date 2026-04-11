class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,pair<int,int>> umap;
        int ans = INT_MAX;

        for(int i = 0 ; i < nums.size() ; i++ ){
            if(umap.find(nums[i]) == umap.end()){
                umap[nums[i]] = pair<int,int> {i, -1};
            }
            else if(umap[nums[i]].second == -1){
                umap[nums[i]].second = i;
            }
            else{
                ans = min(ans, 2*(i - umap[nums[i]].first));
                umap[nums[i]].first = umap[nums[i]].second;
                umap[nums[i]].second = i;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};