class Solution {
public:
    int change(int sum, vector<int>& coins) {

        int n = coins.size();
        vector<vector<long long>> dp(n+1,vector<long long>(sum+1));
        
        
        for(int i = 0;i<=n;i++)
           for(int j = 0;j<=sum;j++){
              
                  if(j == 0) dp[i][j] = 1;
                  else if(i == 0) dp[i][j] = 0;
                  else{
                   int take = (j - coins[i-1] < 0)  ? 0 : dp[i][j - coins[i-1]];
                   dp[i][j] = dp[i-1][j] + take;
                   
                  }
              
           }
           
           
           return dp[n][sum];
        
    }
};