class Solution {
public:
    long long mod = 1e9 + 7;
    int countStableSubsequences(vector<int>& nums) {

        vector<vector<long long>> dp(nums.size() + 1, vector<long long> (4,0));
        int n = nums.size();
        for(int i = 1;i<=n;i++){

            if(nums[i-1]%2){
                dp[i][0] = dp[i-1][0];
                dp[i][1] = (dp[i-1][1] + dp[i-1][0] + dp[i-1][3]+ 1)%mod;
                dp[i][2] =  (dp[i-1][2] + dp[i-1][1])%mod;
                dp[i][3] = dp[i-1][3];
                
            }
            else{
                dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + 1)%mod;
                dp[i][1] = dp[i-1][1];
                dp[i][2] =  dp[i-1][2];
                dp[i][3] = (dp[i-1][3] + dp[i-1][0])%mod;
                
            }
        }


        return ((dp[n][0] + dp[n][1])%mod + (dp[n][2] + dp[n][3])%mod)%mod;
        
        
        
    }
};