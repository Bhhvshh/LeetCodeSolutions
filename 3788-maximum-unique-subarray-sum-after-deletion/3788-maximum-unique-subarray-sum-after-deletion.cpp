class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0;
        unordered_map<int,int> umap;
        for(auto x:nums){
            if(umap[x] || x<=0) continue;
            sum+=x;
            umap[x] = 1;
        }
        if(sum==0) sum = *max_element(nums.begin(),nums.end());
        return sum;
        
    }
};