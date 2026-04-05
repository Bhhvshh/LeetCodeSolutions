class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        
        vector<vector<vector<int>>> dp(coins.size() + 1, vector<vector<int>> (coins[0].size() + 1, vector<int> (3, -60000000)));
        dp[0][1][0] = dp[1][0][0] = 0;
        for(int i = 1;i <= coins.size(); i++){
            for(int j = 1;j <= coins[0].size(); j++){
                dp[i][j][0] = coins[i - 1][j - 1] + max(dp[i - 1][j][0], dp[i][j - 1][0]);
                // cout << dp[i][j][0] << " ";

                for(int k = 1; k <= 2; k++){
                    dp[i][j][k] = max(dp[i - 1][j][k - 1], dp[i][j - 1][k - 1]) ;
                    dp[i][j][k] = max( dp[i][j][k], coins[i - 1][j -1] + max(dp[i - 1][j][k], dp[i][j - 1][k]));
                    // cout << dp[i][j][k] << " ";
                }

                // cout << "\n";
            }
        }


        return max( max(dp[coins.size()][coins[0].size()][0], dp[coins.size()][coins[0].size()][1]), dp[coins.size()][coins[0].size()][2]);
    }
};