class Solution {
public:
    int maxProduct(vector<int>& nums) {


        vector<vector<int>> dp(nums.size(),vector<int>(2,0));

        int ans = INT_MIN;

        for(int i = 0;i<nums.size();i++){
            if(i==0){
                dp[i][0] = nums[i];
                dp[i][1] = nums[i];
            }
            else{
                int min_ = min(min(dp[i-1][0]*nums[i],dp[i-1][1]*nums[i]),nums[i]);
                int max_ = max(max(dp[i-1][0]*nums[i],dp[i-1][1]*nums[i]),nums[i]);
                dp[i][0] = max_;
                dp[i][1] = min_;
            }

            ans = max(ans,dp[i][0]);

        }
        

        return ans;
    }
};