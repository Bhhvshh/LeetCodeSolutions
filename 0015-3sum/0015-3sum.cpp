class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        unordered_map<long long,bool> umap;
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<long long>> s;
        sort(nums.begin(),nums.end());
        umap[nums[0]] = true;


        for(int i = 1;i<n;i++){
            for(int j = i+1;j<n;j++){
                long long target = (long long)-nums[i]-nums[j];
                if(umap[target]){
                vector<long long> tmp = {target,nums[i],nums[j]};
                // for(auto x:tmp) cout << x << " ";
                if(umap.find(target)!=umap.end() && s.find(tmp) ==s.end()){
                    ans.push_back({(int)target,nums[i],nums[j]});
                    s.insert(tmp);
                }
                }


            }
            umap[nums[i]] = true;
        }

        return ans;
        
    }
};