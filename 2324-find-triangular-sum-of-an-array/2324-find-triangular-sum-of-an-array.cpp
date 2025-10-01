class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<vector<int>> memo(nums.size()+1,vector<int>(nums.size(),-1));
         return helper(nums.size(),0,nums,memo);
       
        
    }
    int helper(int h,int id,vector<int>&nums,vector<vector<int>> &memo){
        if(h==1)  return nums[id];
        if(memo[h][id]!=-1) return memo[h][id];

        return memo[h][id]=(helper(h-1,id,nums,memo)+helper(h-1,id+1,nums,memo))%10;
        
    }
};