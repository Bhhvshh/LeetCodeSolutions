class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_ = 0;
        for(auto x:nums) max_|=x;
        int count = 0;
        helper(0,0,nums,count,max_);

        return count;
    }

    void helper(int id,int curr,vector<int> &nums,int &count,int &max_){
        if(id == nums.size()){
            if(curr==max_) count++;
            return;
        }

        helper(id+1,curr|nums[id],nums,count,max_);
        helper(id+1,curr,nums,count,max_);
    }
};