class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
         int xor_ = 0;
        bool flag = true;
        for(auto x:nums) {xor_^=x;  if(x) flag = false;}
        if(flag) return 0;

        return (xor_==0) ? nums.size()-1: nums.size();
    
    }
};