class Solution {
public:
int coin2(vector<int> &demo,int tar){
    int n = demo.size() +1;
    vector<vector<int>> dp(n,vector<int>(tar+1));
    dp[0][0] = 1;

    for(int i =1;i<n;i++)
     for(int j = 0;j<=tar;j++)
        dp[i][j] = dp[i-1][j] + ((j-demo[i-1]>=0) ? dp[i][j-demo[i-1]] : 0);

    return dp[n-1][tar];
}
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> demo;
        vector<int> dp(n+1);
        dp[0] = 1;

        for(int i = 0;i<n;i++){
            if(dp[i+1]==numWays[i]-1){
                demo.push_back(i+1);
                for(int j = i+1;j<=n;j++){
                    dp[j]+=dp[j-i-1];
                }
            }
            else if(dp[i+1]!=numWays[i]) return {};
        }

        return demo;
        
    }
};