class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {

        // vector<long long> dp(nums.size(),vector<long long>(k+1,-1));
        int ans = 0;

        
        // int ans = 0;

        for(int i = 0;i<k;i++){
            int curr = 0;
        unordered_map<int,int> umap;

           for(int j = 0;j<nums.size();j++){
            umap[nums[j]%k] = max(umap[nums[j]%k], 1 + umap[(i - (nums[j]%k) + k)%k]);
            curr = max(curr,umap[nums[j]%k]);
           }
            ans = max(ans,curr);
        }
        
        return ans;


        
    }

    // int helper(vector<int> &nums,int &k,int need,int last,int id,vector<vector<long long>> &dp)
    // {
    //     if(id==nums.size()) return 0;
        
    //     int take = 0, notake = 0;

    //     take = 1 + 



    // }
};