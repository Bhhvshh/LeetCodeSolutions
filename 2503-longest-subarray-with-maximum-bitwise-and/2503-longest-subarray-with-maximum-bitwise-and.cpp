class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_ = *max_element(nums.begin(), nums.end());

        int ans = 1;
        int curr = 0;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]==max_){
               
                ans = max(ans,++curr);
            }
            else curr = 0;
        }


        return ans;
        
    }
};